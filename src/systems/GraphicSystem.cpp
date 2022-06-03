/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GraphicSystem.cpp
*/

#include "GraphicSystem.hpp"
#include "String.hpp"
#include "Texture2D.hpp"
#include "Position.hpp"

#include <iostream>

#include "raylib.h"
namespace indie
{

    GraphicSystem::GraphicSystem()
    {
    }
    void GraphicSystem::init(SceneManager &)
    {
        std::cout << "GraphicSystem::init" << std::endl;
        _window = std::make_unique<Window>(800, 600, FLAG_WINDOW_RESIZABLE, "Indie Studio");
    }

    void GraphicSystem::update(SceneManager &sceneManager, uint64_t)
    {
        if (_window->shouldClose()) {
            sceneManager.setShouldClose(true);
            return;
        }
        _window->beginDraw();
        _window->clearBackground(RAYWHITE);
        for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::RENDERABLE_2D]) {
            std::cout << "render 2D img" << std::endl;
        }
        for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::RENDERABLE_3D]) {
            std::cout << "render 3D img" << std::endl;
        }
        _window->endDraw();
    }

    void GraphicSystem::destroy()
    {
        std::cout << "GraphicSystem::destroy" << std::endl;
    }

    void GraphicSystem::loadEntity(std::shared_ptr<IEntity>)
    {
        std::cout << "GraphicSystem::loadEntity" << std::endl;
    }

    void GraphicSystem::unloadEntity(std::shared_ptr<IEntity>)
    {
        std::cout << "GraphicSystem::unloadEntity" << std::endl;
    }

}