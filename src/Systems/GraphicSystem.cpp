/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GraphicSystem.cpp
*/

#include <iostream>

#include "GraphicSystem.hpp"

namespace indie {

    void GraphicSystem::init(SceneManager &)
    {
        std::cout << "GraphicSystem::init" << std::endl;
    }

    void GraphicSystem::update(SceneManager &sceneManager, uint64_t)
    {
        std::cout << "GraphicSystem::update" << std::endl;
        for (auto &e : sceneManager.getCurrentScene().getEntities()) {
            std::cout << e->getName() << std::endl;
        }
    }

    void GraphicSystem::destroy()
    {
        std::cout << "GraphicSystem::destroy" << std::endl;
    }

}