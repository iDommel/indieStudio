/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GameSystem.cpp
*/

#include <iostream>

#include "GameSystem.hpp"

namespace indie {

    void GameSystem::init(SceneManager &)
    {
        std::cout << "GameSystem::init" << std::endl;
    }

    void GameSystem::update(SceneManager &)
    {
        std::cout << "GameSystem::update" << std::endl;
    }

    void GameSystem::destroy()
    {
        std::cout << "GameSystem::destroy" << std::endl;
    }

}