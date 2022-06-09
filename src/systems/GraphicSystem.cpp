/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GraphicSystem.cpp
*/


#include <iostream>
#include "raylib.h"

#include "GraphicSystem.hpp"
#include "Texture2D.hpp"
#include "Sprite.hpp"
#include "Position.hpp"

namespace indie
{

    GraphicSystem::GraphicSystem()
    {
    }
    void GraphicSystem::init(SceneManager &sceneManager)
    {
        std::cout << "GraphicSystem::init" << std::endl;
        _window = std::make_unique<Window>(800, 600, FLAG_WINDOW_RESIZABLE, "Indie Studio");

        for (auto &scene : sceneManager.getScenes()) {
            for (auto &entity : (*scene.second)[IEntity::Tags::SPRITE_2D])
                loadSprite(entity);
        }
    }

    void GraphicSystem::update(SceneManager &sceneManager, uint64_t)
    {
        if (_window->shouldClose()) {
            sceneManager.setShouldClose(true);
            return;
        }
        _window->beginDraw();
        _window->clearBackground(RAYWHITE);
        for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D]) {
            displaySprite(e);
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

    void GraphicSystem::loadEntity(std::shared_ptr<IEntity> entity)
    {
        std::cout << "loadEntity" << std::endl;
        if (entity->hasTag(IEntity::Tags::SPRITE_2D)) {
            std::cout << "loadSprite" << std::endl;
            loadSprite(entity);
        }
    }

    void GraphicSystem::unloadEntity(std::shared_ptr<IEntity> entity)
    {
        if (entity->hasTag(IEntity::Tags::SPRITE_2D)) {
            unloadSprite(entity);
        }
    }

    void GraphicSystem::loadSprite(std::shared_ptr<IEntity> &entity)
    {
        auto components = entity->getFilteredComponents({ IComponent::Type::SPRITE });

        if (components.size() != 1)
            throw std::runtime_error("GraphicSystem::loadSprite could not get component Sprite from entity");

        auto sprite = Component::castComponent<Sprite>(components[0]);
        if (_textures.find(sprite->getValue()) != _textures.end()) {
            _textures[sprite->getValue()].second++;
            std::cout << "Sprite " << sprite->getValue() << std::endl;
        } else {
            _textures[sprite->getValue()] = std::make_pair<std::unique_ptr<Texture>, int>(std::make_unique<Texture>(sprite->getValue()), 1);
        }
    }

    void GraphicSystem::unloadSprite(std::shared_ptr<IEntity> &entity)
    {
        auto components = entity->getFilteredComponents({ IComponent::Type::SPRITE });

        if (components.size() != 1)
            throw std::runtime_error("GraphicSystem::unloadSprite could not get sprite component from entity");

        auto sprite = Component::castComponent<Sprite>(components[0]);
        if (_textures[sprite->getValue()].second != 1)
            _textures[sprite->getValue()].second--;
        else
            _textures.erase(sprite->getValue());
    }

    void GraphicSystem::displaySprite(std::shared_ptr<IEntity> &entity) const
    {
        auto components = entity->getFilteredComponents({ IComponent::Type::SPRITE, IComponent::Type::VECTOR });

        if (components.size() != 2)
            throw std::runtime_error("GraphicSystem::loadSprite could not get component Sprite & Vector from entity");

        auto sprite = Component::castComponent<Sprite>(components[0]);
        auto pos = Component::castComponent<Position>(components[1])->getPosition();

        _textures.at(sprite->getValue()).first->draw(std::get<0>(pos), std::get<1>(pos));
    }
}