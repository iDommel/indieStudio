/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** generateMap.cpp
*/

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include "raylib.h"

#include "IScene.hpp"
#include "Entity.hpp"
#include "Position.hpp"
#include "Sprite.hpp"
#include "GameSystem.hpp"
#include "Model3D.hpp"
#include "Cube.hpp"
#include "Destructible.hpp"

namespace indie
{

    static const std::vector<std::string> tilesFilepaths = {
        "assets/ground_asset/sand_asset_basic/basicBeach",
        "assets/ground_asset/sand_asset_basic/basicBeach",
        "assets/ground_asset/sand_asset_basic/basicBeach",
        "assets/ground_asset/sand_asset_basic/basicBeach",
        "assets/ground_asset/sand_asset_basic/basicBeach",
        "assets/ground_asset/sand_asset_basic/basicBeach",
        "assets/ground_asset/sand_asset_basic/basicBeach",
        "assets/ground_asset/sand_asset_basic/basicBeach",
        "assets/ground_asset/sand_asset_basic/basicBeach",
        "assets/ground_asset/sand_asset_basic/basicBeach",
        "assets/ground_asset/sand_asset_basic/basicBeach",
        "assets/ground_asset/sand_asset_basic/basicBeach",
        "assets/ground_asset/sand_asset_basic/basicBeach",
        "assets/ground_asset/sand_asset_basic/basicBeach",
        "assets/ground_asset/sand_asset_basic/basicBeach",
        "assets/ground_asset/sand_asset_basic/basicBeach",
        "assets/ground_asset/sand_asset_basic/basicBeach"};

    static const std::string tilesFilepath = "assets/ground_asset/sand_asset_basic/basicBeach";
    static const std::string indestructibleBordersFile = "assets/wall asset/plamier_wall/palmier_wall_1";
    static const std::string indestructibleWallFile = "assets/wall asset/plamier_wall/palmier_wall_1";
    static const std::string wallFilepath = "assets/wall asset/breakable_wall/wood_box_breakable";

    static std::shared_ptr<IEntity> createWall(int x, int y)
    {
        std::shared_ptr<Entity> wall = std::make_shared<Entity>();
        Vector3 size = {GAME_TILE_SIZE, GAME_TILE_SIZE, GAME_TILE_SIZE};
        Vector3 pos = {x, 0, y};
        BoundingBox bbox = {pos, {pos.x + size.x, pos.y + size.y, pos.z + size.z}};

        wall->addComponent(std::make_shared<Position>(x, 0, y))
            .addComponent(std::make_shared<Hitbox>(true))
            .addComponent(std::make_shared<Destructible>())
            // .addComponent(std::make_shared<Cube>(size, BROWN)
            .addComponent(std::make_shared<Model3D>(wallFilepath + ".obj", wallFilepath + ".png"));
        return wall;
    }

    static std::shared_ptr<IEntity> createIndestructibleWall(int x, int y, const std::string &filename)
    {
        std::shared_ptr<Entity> wall = std::make_shared<Entity>();
        Vector3 size = {GAME_TILE_SIZE, GAME_TILE_SIZE, GAME_TILE_SIZE};
        Vector3 pos = {x, 0, y};
        BoundingBox bbox = {pos, {pos.x + size.x, pos.y + size.y, pos.z + size.z}};
        wall->addComponent(std::make_shared<Position>(x, 0, y))
            // .addComponent(std::make_shared<Cube>(size, GREEN))
            .addComponent(std::make_shared<Model3D>(filename + ".obj", filename + ".png"))
            .addComponent(std::make_shared<Hitbox>(true));
        return wall;
    }

    int createRandomWalls(IScene &scene, std::array<std::array<char, GAME_MAP_WIDTH>, GAME_MAP_HEIGHT> &map)
    {
        for (int n = 0; n < GAME_NB_INDESTRUCTIBLE_WALL; n++) {
            int x = std::rand() % (GAME_MAP_WIDTH - 4) + 2;
            int y = std::rand() % (GAME_MAP_HEIGHT - 4) + 2;
            if (map[y][x] != ' ') {
                n--;
                continue;
            }
            map[y][x] = 'H';
            scene.addEntity(createIndestructibleWall(x * GAME_TILE_SIZE, y * GAME_TILE_SIZE, indestructibleWallFile));
        }

        for (int n = 0; n < GAME_NB_DESTRUCTIBLE_WALL; n++) {
            int x = std::rand() % (GAME_MAP_WIDTH - 2) + 1;
            int y = std::rand() % (GAME_MAP_HEIGHT - 2) + 1;
            if (map[y][x] != ' ' || (x <= 2 && (y <= 2 || y >= GAME_MAP_HEIGHT - 3)) || (x >= GAME_MAP_WIDTH - 3 && (y <= 2 || y >= GAME_MAP_HEIGHT - 3))) {
                n--;
                continue;
            }
            map[y][x] = 'D';
            scene.addEntity(createWall(x * GAME_TILE_SIZE, y * GAME_TILE_SIZE));
        }

        return 0;
    }

    static std::shared_ptr<IEntity> createSpawn(int x, int y)
    {
        static unsigned int nb = 0;
        std::shared_ptr<Entity> spawn = std::make_shared<Entity>();

        nb++;
        spawn->addComponent(std::make_shared<Position>(x, 0, y));
        spawn->addComponent(std::make_shared<Sprite>("o"));
        return spawn;
    }

    static std::shared_ptr<IEntity> createGroundTile(int x, int y)
    {
        std::shared_ptr<Entity> groundTile = std::make_shared<Entity>();
        int nb = std::rand() % tilesFilepaths.size();

        groundTile->addComponent(std::make_shared<Position>(x, 0, y))
            .addComponent(std::make_shared<Model3D>(tilesFilepath + ".obj", tilesFilepath + ".png"));
        return groundTile;
    }

    static std::vector<std::shared_ptr<IEntity>> createTiles()
    {
        std::vector<std::shared_ptr<IEntity>> tiles;
        std::srand(std::time(nullptr));

        for (int y = 0; y < GAME_MAP_HEIGHT; y++) {
            for (int x = 0; x < GAME_MAP_WIDTH; x++) {
                tiles.push_back(createGroundTile(x * GAME_TILE_SIZE, y * GAME_TILE_SIZE));
            }
        }
        return tiles;
    }

    void GameSystem::generateMap(const std::string &filename, IScene &scene)
    {
        std::ifstream file(filename);
        std::string line;
        std::array<std::array<char, GAME_MAP_WIDTH>, GAME_MAP_HEIGHT> map;
        int y = -1;

        if (!file.is_open())
            throw std::runtime_error("Could not open map file");
        for (auto &line : map)
            line.fill(' ');
        scene.addEntities(createTiles());
        while (!file.eof()) {
            y++;
            std::getline(file, line);
            for (size_t i = 0; i < line.size(); i++) {
                if (line[i] == '#') {
                    scene.addEntity(createIndestructibleWall(i * GAME_TILE_SIZE, y * GAME_TILE_SIZE, indestructibleBordersFile));
                    map[y][i] = line[i];
                } else if (line[i] == 'H') {
                    scene.addEntity(createIndestructibleWall(i * GAME_TILE_SIZE, y * GAME_TILE_SIZE, indestructibleWallFile));
                    map[y][i] = line[i];
                }
                // else if (line[i] == 'o')
                //     scene.addEntity(createSpawn(i, y));
            }
        }
        file.close();
        createRandomWalls(scene, map);
    }

}