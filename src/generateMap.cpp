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

#include "IScene.hpp"
#include "Entity.hpp"
#include "Position.hpp"
#include "Sprite.hpp"
#include "GameSystem.hpp"
#include "Model3D.hpp"

namespace indie {

    static const std::vector<std::string> tilesFilepaths = {
        "assets/ground_asset/sand_asset_1/sand_asset_1",
        "assets/ground_asset/sand_asset_2/sand_asset_2",
        "assets/ground_asset/sand_asset_3/sand_asset_3",
        "assets/ground_asset/sand_asset_basic/sand_asset_basic",
        "assets/ground_asset/sand_asset_basic/sand_asset_basic",
        "assets/ground_asset/sand_asset_basic/sand_asset_basic",
        "assets/ground_asset/sand_asset_basic/sand_asset_basic",
        "assets/ground_asset/sand_asset_basic/sand_asset_basic",
        "assets/ground_asset/sand_asset_basic/sand_asset_basic",
        "assets/ground_asset/sand_asset_basic/sand_asset_basic",
        "assets/ground_asset/sand_asset_basic/sand_asset_basic",
        "assets/ground_asset/sand_asset_basic/sand_asset_basic",
        "assets/ground_asset/sand_asset_basic/sand_asset_basic",
        "assets/ground_asset/sand_asset_basic/sand_asset_basic",
        "assets/ground_asset/sand_asset_basic/sand_asset_basic",
        "assets/ground_asset/sand_asset_basic/sand_asset_basic",
        "assets/ground_asset/sand_asset_basic/sand_asset_basic",
        "assets/ground_asset/sand_asset_basic/sand_asset_basic",
        "assets/ground_asset/sand_asset_basic/sand_asset_basic",
        "assets/ground_asset/sand_asset_basic/sand_asset_basic",
    };

    static const std::string wallFilepath = "assets/wall asset/plamier_wall/palmier_wall_1";

    static std::shared_ptr<IEntity> createWall(int x, int y)
    {
        std::shared_ptr<Entity> wall = std::make_shared<Entity>();

        wall->addComponent(std::make_shared<Position>(x, 0, y))
            .addComponent(std::make_shared<Model3D>(wallFilepath + ".obj", wallFilepath + ".png"));
        return wall;
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
                    .addComponent(std::make_shared<Model3D>(tilesFilepaths[nb] + ".obj", tilesFilepaths[nb] + ".png"));
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
        int y = -1;

        if (!file.is_open())
            throw std::runtime_error("Could not open map file");
        // extraction des donnees et creation des entités
        scene.addEntities(createTiles());
        while (!file.eof()) {
            y++;
            std::getline(file, line);
            for (size_t i = 0; i < line.size(); i++) {
                if (line[i] == '#')
                    scene.addEntity(createWall(i * GAME_TILE_SIZE, y * GAME_TILE_SIZE));
                // else if (line[i] == 'o')
                //     scene.addEntity(createSpawn(i, y));
            }
        }
        file.close();
    }

}