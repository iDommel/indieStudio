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
        for (auto &e : sceneManager.getCurrentScene().getEntities()) {
            if (e->hasTag(IEntity::Tags::RENDERABLE_2D))
                std::cout << "render 2D img" << std::endl;
            else if (e->hasTag(IEntity::Tags::RENDERABLE_3D))
                std::cout << "render 3D img" << std::endl;
        }
    }

    void GraphicSystem::destroy()
    {
        std::cout << "GraphicSystem::destroy" << std::endl;
    }

    void GraphicSystem::loadEntity(std::shared_ptr<IEntity> entity)
    {
        std::cout << "GraphicSystem::loadEntity" << std::endl;
    }

}