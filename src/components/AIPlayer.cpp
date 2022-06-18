/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Player
*/
#include "raylib.h"
#include "AIPlayer.hpp"


#include <functional>
#include <cmath>

#include "ButtonCallbacks.hpp"
#include "Entity.hpp"
#include "Position.hpp"
#include "Velocity.hpp"
#include "HitboxComponent.hpp"
#include "Bomb.hpp"
#include "Sphere.hpp"
#include "GameSystem.hpp"

namespace indie
{

    AIPlayer::AIPlayer(int id) : Component(Type::AI), _id(id)
    {
    }

    void AIPlayer::handleBonus()
    {
    }

    void AIPlayer::move(std::shared_ptr<Velocity> vel)
    {
        // vel->z = (_speed * _isDown) + (-_speed * _isUp);
        // vel->x = (_speed * _isRight) + (-_speed * _isLeft);
    }

    int AIPlayer::getId() const
    {
        return _id;
    }

    int AIPlayer::getSpeed() const
    {
        return _speed;
    }

    int AIPlayer::getNbBomb() const
    {
        return _nbBombMax;
    }

    void AIPlayer::setNbBomb(int newNbBomb)
    {
        _nbBombMax = newNbBomb;
    }

    void AIPlayer::generateBomb(SceneManager &manager, std::shared_ptr<IEntity> entity)
    {
        if (_bombs.size() >= _nbBombMax)
            return;

        std::shared_ptr<Entity> bomb = std::make_shared<Entity>();
        auto pos = Component::castComponent<Position>((*entity)[Component::Type::POSITION]);
        Vector3 size = {GAME_TILE_SIZE, GAME_TILE_SIZE, GAME_TILE_SIZE};
        Vector3 bPos = {std::roundf(pos->x / GAME_TILE_SIZE) * GAME_TILE_SIZE - GAME_TILE_SIZE/2, pos->y, std::roundf(pos->z / GAME_TILE_SIZE) * GAME_TILE_SIZE - GAME_TILE_SIZE/2};

        bomb->addComponent(std::make_shared<Bomb>(_blastPower))
            .addComponent(std::make_shared<Position>(std::roundf(pos->x / GAME_TILE_SIZE) * GAME_TILE_SIZE, pos->y, std::roundf(pos->z / GAME_TILE_SIZE) * GAME_TILE_SIZE))
            .addComponent(std::make_shared<Sphere>(GAME_TILE_SIZE / 2, BLUE))
            .addComponent(std::make_shared<Hitbox>(CollideSystem::makeBBoxFromSizePos(size, bPos)));
        _bombs.push_back(bomb);
        manager.getCurrentScene().addEntity(bomb);
    }

    void AIPlayer::updateBombsVec()
    {
        for (auto bomb = _bombs.begin(); bomb != _bombs.end();) {
            auto b = Component::castComponent<Bomb>((**bomb)[IComponent::Type::BOMB]);
            if (b->getTimer() <= 0)
                bomb = _bombs.erase(std::find(_bombs.begin(), _bombs.end(), *bomb));
            else
                bomb++;
        }
    }
}
