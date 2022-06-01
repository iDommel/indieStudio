/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** generateMap.cpp
*/

#include <string>
#include <fstream>
#include <iostream>

#include "IScene.hpp"
#include "Entity.hpp"
#include "components/Position.hpp"
#include "components/Sprite.hpp"

namespace indie {

    static std::shared_ptr<IEntity> createWall(int x, int y)
    {
        std::shared_ptr<Entity> wall = std::make_shared<Entity>();

        wall->addComponent(std::make_shared<Position>(x, y));
        wall->addComponent(std::make_shared<Sprite>("#"));
        return wall;
    }

    void generateMap(const std::string &filename, IScene &scene)
    {
        std::ifstream file(filename);
        std::string line;
        int y = -1;

        if (!file.is_open())
            throw std::runtime_error("Could not open map file");
        // extraction des donnees et creation des entités
        while (!file.eof()) {
            y++;
            std::getline(file, line);
            for (size_t i = 0; i < line.size(); i++) {
                if (line[i] == '#')
                    scene.addEntity(createWall(i, y));
            }
        }
        file.close();
    }

}