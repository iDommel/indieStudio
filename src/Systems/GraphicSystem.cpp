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

    void GraphicSystem::update(SceneManager &)
    {
        std::cout << "GraphicSystem::update" << std::endl;
    }

    void GraphicSystem::destroy()
    {
        std::cout << "GraphicSystem::destroy" << std::endl;
    }

}