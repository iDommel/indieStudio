/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GraphicSystem.cpp
*/

#include <iostream>
#include "raylib.h"

#include "GraphicSystem.hpp"
#include "components/Position.hpp"
#include "components/Sprite.hpp"

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
        auto render2D = sceneManager.getCurrentScene().getTaggedEntities({IEntity::Tags::RENDERABLE_2D});

        displaySprite(render2D);
        // for (auto &e : sceneManager.getCurrentScene().getEntities()) {
        //     if (e->hasTag(IEntity::Tags::RENDERABLE_2D))
        //         std::cout << "render 2D img" << std::endl;
        //     else if (e->hasTag(IEntity::Tags::RENDERABLE_3D))
        //         std::cout << "render 3D img" << std::endl;
        // }
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

    void GraphicSystem::displaySprite(std::vector<std::shared_ptr<IEntity>> &entities)
    {
        std::vector<IComponent::Type> types = {IComponent::Type::SPRITE, IComponent::Type::VECTOR};
        for (auto &e : entities) {
            auto com = e->getComponents(types);
            auto s = std::dynamic_pointer_cast<Sprite>(com[0]);
            auto pos = std::dynamic_pointer_cast<Position>(com[1]);

            std::cout << s->getValue() << ": x=" << std::get<0>(pos->getPosition()) << " y=" << std::get<1>(pos->getPosition()) << std::endl;
        }
    }

}