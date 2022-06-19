/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** AISystem.cpp
*/

#include <cmath>
#include "raylib.h"

#include "AISystem.hpp"
#include "SceneManager.hpp"
#include "GameSystem.hpp"

#include "Position.hpp"
#include "Velocity.hpp"
#include "HitboxComponent.hpp"
#include "AIPlayer.hpp"

#define MAP_EMPTY 0
#define MAP_WALL 1
#define MAP_BOMB 2
#define MAP_INDESTRUCTIBLE_WALL 3
#define MAP_PLAYER 4

namespace indie
{

    AISystem::AISystem(CollideSystem &collideSystem) : _collideSystem(collideSystem) {}

    void AISystem::init(SceneManager &)
    {
    }

    void AISystem::update(SceneManager &manager, uint64_t)
    {
        for (auto &e : manager.getCurrentScene()[IEntity::Tags::AI]) {
            auto ai = Component::castComponent<AIPlayer>((*e)[Component::Type::AI]);
            auto pos = Component::castComponent<Position>((*e)[Component::Type::POSITION]);
            std::array<std::array<char, 5>, 5> map = {{MAP_EMPTY}};

            loadMap(*ai, map, *pos, e);
            moveAI(map, *ai, e, manager);
        }
    }

    void AISystem::loadMap(AIPlayer &ai, std::array<std::array<char, 5>, 5> &map, Position &player, std::shared_ptr<IEntity> me)
    {
        // std::cout << (player.x / GAME_TILE_SIZE) << " " << (player.z / GAME_TILE_SIZE) << std::endl;
        float px = (player.x / GAME_TILE_SIZE);
        float pz = (player.z / GAME_TILE_SIZE);

        if (ai._isUp) {
            pz = (pz - std::floor(pz)) > 0.05 ? std::floor(pz) + 1 : std::floor(pz);
        } else if (ai._isDown) {
            pz = (pz - std::floor(pz)) > 0.95 ? std::floor(pz) + 1 : std::floor(pz);
        } else
            pz = std::floor(pz);

        if (ai._isLeft) {
            px = (px - std::floor(px)) > 0.05 ? std::floor(px) + 1 : std::floor(px);
        } else if (ai._isRight) {
            px = (px - std::floor(px)) > 0.95 ? std::floor(px) + 1 : std::floor(px);
        } else
            px = std::floor(px);
        ai.tileX = px;
        ai.tileY = pz;
        // std::cout << "pz = " << pz << " px = " << px << std::endl;

        for (auto &collider : _collideSystem.getColliders(ai.getRadar())) {
            if (collider->hasTag(IEntity::Tags::TIMED))
                loadExplosionInMap(map, collider, px, pz);
            std::shared_ptr<Position> pos;

            try {
                pos = Component::castComponent<Position>((*collider)[IComponent::Type::POSITION]);
            } catch (std::exception &e) {
                continue;
            }

            if (collider->hasTag(IEntity::Tags::COLLIDABLE) && collider != me) {

                int y = std::round(pos->z / GAME_TILE_SIZE) - (pz - 2);
                int x = std::round(pos->x / GAME_TILE_SIZE) - (px - 2);

                if (x < 0 || y < 0 || x >= 5 || y >= 5)
                    continue;
                if (collider->hasTag(IEntity::Tags::BOMB)) {
                    map[y][x] = MAP_BOMB;
                    if (y - 1 > 0 && map[y-1][x] == MAP_EMPTY)
                        map[y-1][x] = MAP_BOMB;
                    if (y + 1 < 5 && map[y+1][x] == MAP_EMPTY)
                        map[y+1][x] = MAP_BOMB;
                    if (x - 1 > 0 && map[y][x-1] == MAP_EMPTY)
                        map[y][x-1] = MAP_BOMB;
                    if (x + 1 < 5 && map[y][x+1] == MAP_EMPTY)
                        map[y][x+1] = MAP_BOMB;
                } else if (collider->hasTag(IEntity::Tags::DESTRUCTIBLE)) {
                    if (collider->hasTag(IEntity::Tags::PLAYER))
                        map[y][x] = MAP_PLAYER;
                    else
                        map[y][x] = MAP_WALL;
                } else if (!collider->hasTag(IEntity::Tags::BONUS))
                    map[y][x] = MAP_INDESTRUCTIBLE_WALL;
            }
        }
    }

    void AISystem::loadExplosionInMap(std::array<std::array<char, 5>, 5> &map, std::shared_ptr<IEntity> &explosion, int px, int pz)
    {
        auto box = Component::castComponent<Hitbox>((*explosion)[IComponent::Type::HITBOX]);
        BoundingBox bbox = box->getBBox();
        int x = std::round((bbox.min.x + 1) / GAME_TILE_SIZE) - (px - 2);
        int y = std::round((bbox.min.z + 1) / GAME_TILE_SIZE) - (pz - 2);

        if (x < 0 || y < 0 || x >= 5 || y >= 5)
            return;
        if (bbox.max.x - bbox.min.x < bbox.max.z - bbox.min.z) {
            if (y + 1 < 5)
                map[y + 1][x] = MAP_BOMB;
            if (map[y][x] == MAP_EMPTY)
                map[y][x] = MAP_BOMB;
            if (y + 2 < 5 && map[y + 2][x] == MAP_EMPTY)
                map[y + 2][x] = MAP_BOMB;
        } else {
            if (x + 1 < 5)
                map[y][x + 1] = MAP_BOMB;
            if (map[y][x] == MAP_EMPTY)
                map[y][x] = MAP_BOMB;
            if (x + 2 < 5 && map[y][x + 2] == MAP_EMPTY)
                map[y][x + 2] = MAP_BOMB;
        }
    }

    void AISystem::moveAI(std::array<std::array<char, 5>, 5> &map, AIPlayer &ai, std::shared_ptr<IEntity> entity, SceneManager &sceneManager)
    {
        Vector2 pos = {2, 2};


        if (ai._isUp) {
            if (map[pos.y - 1][pos.x] == MAP_EMPTY)
                return;
            else
                ai.stopUp(entity);
        } else if (ai._isDown) {
            if (map[pos.y + 1][pos.x] == MAP_EMPTY)
                return;
            else
                ai.stopDown(entity);
        } else if (ai._isLeft) {
            if (map[pos.y][pos.x - 1] == MAP_EMPTY)
                return;
            else
                ai.stopLeft(entity);
        } else if (ai._isRight) {
            if (map[pos.y][pos.x + 1] == MAP_EMPTY)
                return;
            else
                ai.stopRight(entity);
        }

        if (escape(ai, map, entity))
            return;

        auto position = Component::castComponent<Position>((*entity)[Component::Type::POSITION]);
        poseBomb(ai, sceneManager, map);
        changeDir(map, ai, entity);

    }

    bool AISystem::escape(AIPlayer &ai, std::array<std::array<char, 5>, 5> &map, std::shared_ptr<IEntity> entity)
    {
        Vector2 pos = {2, 2};
        std::vector<DIRECTION> dirs;

        if (map[pos.y][pos.x] != MAP_BOMB) {
            return false;
        }

        // displayMap(map);

        // if (ai._isUp && (map[pos.y - 1][pos.x] == MAP_BOMB || map[pos.y - 1][pos.x] == MAP_EMPTY))
        //     return true;
        // else if (ai._isDown && (map[pos.y + 1][pos.x] == MAP_BOMB || map[pos.y + 1][pos.x] == MAP_EMPTY))
        //     return true;
        // else if (ai._isLeft && (map[pos.y][pos.x - 1] == MAP_BOMB || map[pos.y][pos.x - 1] == MAP_EMPTY))
        //     return true;
        // else if (ai._isRight && (map[pos.y][pos.x + 1] == MAP_BOMB || map[pos.y][pos.x + 1] == MAP_EMPTY))
        //     return true;


        if (map[pos.y - 1][pos.x] == MAP_EMPTY)
            dirs.push_back(DIRECTION::UP);
        if (map[pos.y + 1][pos.x] == MAP_EMPTY)
            dirs.push_back(DIRECTION::DOWN);
        if (map[pos.y][pos.x - 1] == MAP_EMPTY)
            dirs.push_back(DIRECTION::LEFT);
        if (map[pos.y][pos.x + 1] == MAP_EMPTY)
            dirs.push_back(DIRECTION::RIGHT);

        if (dirs.size() == 0) {
            if (map[pos.y - 1][pos.x] == MAP_BOMB)
                dirs.push_back(DIRECTION::UP);
            if (map[pos.y + 1][pos.x] == MAP_BOMB)
                dirs.push_back(DIRECTION::DOWN);
            if (map[pos.y][pos.x - 1] == MAP_BOMB)
                dirs.push_back(DIRECTION::LEFT);
            if (map[pos.y][pos.x + 1] == MAP_BOMB)
                dirs.push_back(DIRECTION::RIGHT);
            if (dirs.size() == 0)
                return true;
        }

        int dir = std::rand() % dirs.size();
        if (dirs[dir] == DIRECTION::UP)
            ai.moveUp(entity);
        else if (dirs[dir] == DIRECTION::DOWN)
            ai.moveDown(entity);
        else if (dirs[dir] == DIRECTION::LEFT)
            ai.moveLeft(entity);
        else if (dirs[dir] == DIRECTION::RIGHT)
            ai.moveRight(entity);

        // std::cout << "DIR: " << (int)dirs[dir] << std::endl << std::endl;
        return true;
    }

    void AISystem::changeDir(std::array<std::array<char, 5>, 5> &map, AIPlayer &ai, std::shared_ptr<IEntity> entity)
    {
        Vector2 pos = {2, 2};
        std::vector<DIRECTION> dirs;

        if (map[pos.y - 1][pos.x] == MAP_EMPTY)
            dirs.push_back(DIRECTION::UP);
        if (map[pos.y + 1][pos.x] == MAP_EMPTY)
            dirs.push_back(DIRECTION::DOWN);
        if (map[pos.y][pos.x - 1] == MAP_EMPTY)
            dirs.push_back(DIRECTION::LEFT);
        if (map[pos.y][pos.x + 1] == MAP_EMPTY)
            dirs.push_back(DIRECTION::RIGHT);

        if (dirs.size() == 0)
            return;
        int dir = std::rand() % dirs.size();
        if (dirs[dir] == DIRECTION::UP)
            ai.moveUp(entity);
        else if (dirs[dir] == DIRECTION::DOWN)
            ai.moveDown(entity);
        else if (dirs[dir] == DIRECTION::LEFT)
            ai.moveLeft(entity);
        else if (dirs[dir] == DIRECTION::RIGHT)
            ai.moveRight(entity);

        // std::cout << "DIR: " << (int)dirs[dir] << std::endl << std::endl;
    }

    void AISystem::poseBomb(AIPlayer &ai, SceneManager &sceneManager, std::array<std::array<char, 5>, 5> &map)
    {
        int y = 2;
        int x = 2;
        int rand = std::rand() % 25;
        Vector3 posBomb = {ai.tileX * 1.0f * GAME_TILE_SIZE, 0.0f, ai.tileY * 1.0f * GAME_TILE_SIZE};

        if (rand != 0)
            return;

        if ((map[y - 1][x - 1] != MAP_EMPTY || (map[y - 1][x] != MAP_EMPTY && map[y][x - 1] != MAP_EMPTY)) &&
        (map[y - 1][x + 1] != MAP_EMPTY || (map[y - 1][x] != MAP_EMPTY && map[y][x + 1] != MAP_EMPTY)) &&
        (map[y + 1][x - 1] != MAP_EMPTY || (map[y + 1][x] != MAP_EMPTY && map[y][x - 1] != MAP_EMPTY)) &&
        (map[y + 1][x + 1] != MAP_EMPTY || (map[y + 1][x] != MAP_EMPTY && map[y][x + 1] != MAP_EMPTY)))
            return;

        // if ((map[y + 1][x + 1] != MAP_EMPTY && !(map[y + 1][x] == MAP_EMPTY || map[y][x + 1] == MAP_EMPTY)) &&
        // (map[y - 1][x - 1] != MAP_EMPTY && !(map[y - 1][x] == MAP_EMPTY || map[y][x - 1] == MAP_EMPTY)) &&
        // (map[y + 1][x - 1] != MAP_EMPTY && !(map[y + 1][x] == MAP_EMPTY || map[y][x - 1] == MAP_EMPTY)) &&
        // (map[y - 1][x + 1] != MAP_EMPTY && !(map[y - 1][x] == MAP_EMPTY || map[y][x + 1] == MAP_EMPTY)))
        //     return;
        ai.generateBomb(sceneManager, posBomb);
        // displayMap(map);
    }

    void AISystem::displayMap(std::array<std::array<char, 5>, 5> &map)
    {
        for (auto &i : map) {
            for (auto &j : i)
                std::cout << (int)j << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void AISystem::destroy()
    {
    }

    void AISystem::loadEntity(std::shared_ptr<IEntity>)
    {
    }

    void AISystem::unloadEntity(std::shared_ptr<IEntity>)
    {
    }

}