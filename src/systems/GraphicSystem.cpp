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
#include "Rect.hpp"
#include "Model3D.hpp"
#include "CameraComponent.hpp"

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
            for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::RENDERABLE_3D])
                loadModel(e);
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

        for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::CAMERA]) {
            auto camComponents = e->getFilteredComponents({ IComponent::Type::CAMERA });
            if (camComponents.size() == 0)
                continue;
            auto cam = Component::castComponent<CameraComponent>(camComponents[0]);
            cam->getCamera().beginDrawScope();
            for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::RENDERABLE_3D])
                displayModel(e);
            cam->getCamera().endDrawScope();
        }
        for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D])
            displaySprite(e);
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
        if (entity->hasTag(IEntity::Tags::RENDERABLE_3D)) {
            std::cout << "loadModel" << std::endl;
            loadModel(entity);
        }
    }

    void GraphicSystem::unloadEntity(std::shared_ptr<IEntity> entity)
    {
        if (entity->hasTag(IEntity::Tags::SPRITE_2D))
            unloadSprite(entity);
        if (entity->hasTag(IEntity::Tags::RENDERABLE_3D))
            unloadModel(entity);
    }

    void GraphicSystem::loadSprite(std::shared_ptr<IEntity> &entity)
    {
        auto components = entity->getFilteredComponents({ IComponent::Type::SPRITE });

        if (components.size() != 1)
            throw std::runtime_error("GraphicSystem::loadSprite could not get component Sprite from entity");

        auto sprite = Component::castComponent<Sprite>(components[0]);
        if (_textures.find(sprite->getValue()) != _textures.end())
            _textures[sprite->getValue()].second++;
        else
            _textures[sprite->getValue()] = std::make_pair<std::unique_ptr<Texture>, int>(std::make_unique<Texture>(sprite->getValue()), 1);
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
        auto pos = Component::castComponent<Position>(components[1]);

        try {
            auto rect = entity->getFilteredComponents({ IComponent::Type::RECT });
            auto r = Component::castComponent<Rect>(rect[0]);
            Vector2 p = {pos->x, pos->y};
            _textures.at(sprite->getValue()).first->setRect(r->left, r->top, r->width, r->height);
            _textures.at(sprite->getValue()).first->drawRec(p);
        } catch (std::invalid_argument &) {
            _textures.at(sprite->getValue()).first->draw(pos->x, pos->y);
        }
    }

    void GraphicSystem::displayModel(std::shared_ptr<IEntity> &entity) const
    {
        auto components = entity->getFilteredComponents({ IComponent::Type::MODEL, IComponent::Type::VECTOR });

        if (components.size() != 2)
            throw std::runtime_error("GraphicSystem::loadSprite could not get component Sprite & Vector from entity");

        auto model = Component::castComponent<Model3D>(components[0]);
        auto pos = Component::castComponent<Position>(components[1]);
        Vector3 position = {pos->x, pos->y, pos->z};

        _models.at(model->getModelPath()).first->draw(position, WHITE);
    }

    void GraphicSystem::loadModel(std::shared_ptr<IEntity> &entity)
    {
        auto components = entity->getFilteredComponents({ IComponent::Type::MODEL });

        if (components.size() != 1)
            throw std::runtime_error("GraphicSystem::loadModel could not get component Model from entity");

        auto model = Component::castComponent<Model3D>(components[0]);
        if (_models.find(model->getModelPath()) != _models.end())
            _models[model->getModelPath()].second++;
        else
            _models[model->getModelPath()] = std::make_pair<std::unique_ptr<Model>, int>(std::make_unique<Model>(model->getModelPath(), model->getTexturePath()), 1);
    }

    void GraphicSystem::unloadModel(std::shared_ptr<IEntity> &entity)
    {
        auto components = entity->getFilteredComponents({ IComponent::Type::MODEL });

        if (components.size() != 1)
            throw std::runtime_error("GraphicSystem::unloadModel could not get component Model from entity");

        auto model = Component::castComponent<Model3D>(components[0]);
        if (_models[model->getModelPath()].second != 1)
            _models[model->getModelPath()].second--;
        else
            _models.erase(model->getModelPath());
    }

}