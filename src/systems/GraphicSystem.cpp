/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GraphicSystem.cpp
*/

#include "raylib.h"

#include "GraphicSystem.hpp"
#include <iostream>

#include "CameraComponent.hpp"
#include "Cube.hpp"
#include "Grid.hpp"
#include "Model3D.hpp"
#include "Position.hpp"
#include "Rect.hpp"
#include "Shape3D.hpp"
#include "Sphere.hpp"
#include "Sprite.hpp"
#include "String.hpp"
#include "Texture2D.hpp"
#include "HitboxComponent.hpp"

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
            for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::TEXT])
                loadText(e);
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
            auto camComponents = e->getFilteredComponents({IComponent::Type::CAMERA});
            if (camComponents.size() == 0)
                continue;
            auto cam = Component::castComponent<CameraComponent>(camComponents[0]);
            cam->getCamera().beginDrawScope();
            for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::RENDERABLE_3D])
                displayModel(e);
            for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::GRID])
                displayGrid(e);
            for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::SPHERE])
                displaySphere(e);
            for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::CUBE])
                displayCube(e);
            for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::COLLIDABLE])
                displayCollidable(e);
            cam->getCamera().endDrawScope();
        }
        for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D])
            displaySprite(e);
        for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::TEXT])
            displayText(e);
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
        auto sprite = Component::castComponent<Sprite>((*entity)[IComponent::Type::SPRITE]);

        if (_textures.find(sprite->getValue()) != _textures.end())
            _textures[sprite->getValue()].second++;
        else
            _textures[sprite->getValue()] = std::make_pair(std::make_unique<Texture>(sprite->getValue()), 1);

        if (sprite->getNbFrame() == 0)
            return;
        auto spriteRect = Component::castComponent<Rect>((*entity)[IComponent::Type::RECT]);

        spriteRect->width = _textures[sprite->getValue()].first->getWidth() / sprite->getNbFrame();
        spriteRect->height = _textures[sprite->getValue()].first->getHeight();
    }

    void GraphicSystem::unloadSprite(std::shared_ptr<IEntity> &entity)
    {
        auto sprite = Component::castComponent<Sprite>((*entity)[IComponent::Type::SPRITE]);

        if (_textures[sprite->getValue()].second != 1)
            _textures[sprite->getValue()].second--;
        else
            _textures.erase(sprite->getValue());
    }

    void GraphicSystem::displaySprite(std::shared_ptr<IEntity> &entity) const
    {
        auto components = entity->getFilteredComponents({IComponent::Type::SPRITE, IComponent::Type::POSITION});
        auto sprite = Component::castComponent<Sprite>(components[0]);
        auto pos = Component::castComponent<Position>(components[1]);

        try {
            auto rect = entity->getFilteredComponents({IComponent::Type::RECT});
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
        auto components = entity->getFilteredComponents({IComponent::Type::MODEL, IComponent::Type::POSITION});
        auto model = Component::castComponent<Model3D>(components[0]);
        auto pos = Component::castComponent<Position>(components[1]);
        Vector3 position = {pos->x, pos->y, pos->z};

        _models.at(model->getModelPath()).first->draw(position, WHITE);
    }

    void GraphicSystem::displayCollidable(std::shared_ptr<IEntity> &entity) const
    {
        auto components = entity->getFilteredComponents({IComponent::Type::HITBOX});
        auto hitbox = Component::castComponent<Hitbox>(components[0]);
        if (hitbox->is3D())
            ::DrawBoundingBox(hitbox->getBBox(), RED);
    }

    void GraphicSystem::loadModel(std::shared_ptr<IEntity> &entity)
    {
        auto model = Component::castComponent<Model3D>((*entity)[IComponent::Type::MODEL]);
        auto hitbox = Component::castComponent<Hitbox>((*entity)[IComponent::Type::HITBOX]);

        if (_models.find(model->getModelPath()) != _models.end())
            _models[model->getModelPath()].second++;
        else
            _models[model->getModelPath()] = std::make_pair(std::make_unique<Model>(model->getModelPath(), model->getTexturePath()), 1);
        if (hitbox->is3D() && !hitbox->isInitialized()) {
            auto box = _models[model->getModelPath()].first->getBoundingBox();
            auto pos = hitbox->getBBox().max;
            box.max.x += pos.x;
            box.max.y += pos.y;
            box.max.z += pos.z;
            box.min.x += pos.x;
            box.min.y += pos.y;
            box.min.z += pos.z;
            hitbox->setBBox(box);
        }
    }

    void GraphicSystem::unloadModel(std::shared_ptr<IEntity> &entity)
    {
        auto model = Component::castComponent<Model3D>((*entity)[IComponent::Type::MODEL]);

        if (_models[model->getModelPath()].second != 1)
            _models[model->getModelPath()].second--;
        else
            _models.erase(model->getModelPath());
    }

    void GraphicSystem::displaySphere(std::shared_ptr<IEntity> &entity) const
    {
        auto components = entity->getFilteredComponents({IComponent::Type::SPHERE, IComponent::Type::POSITION});

        if (components.size() != 2)
            throw std::runtime_error("GraphicSystem::displaySphere could not get component Sphere & Vector from entity");

        auto sphere = Component::castComponent<Sphere>(components[0]);
        auto pos = Component::castComponent<Position>(components[1]);
        Vector3 position = {pos->x, pos->y, pos->z};

        Shape3D::drawSphere(position, sphere->getRadius(), sphere->getColor());
    }

    void GraphicSystem::displayGrid(std::shared_ptr<IEntity> &entity) const
    {
        auto grid = Component::castComponent<Grid>((*entity)[IComponent::Type::GRID]);

        Shape3D::drawGrid(grid->getSlices(), grid->getSpacing());
    }

    void GraphicSystem::displayCube(std::shared_ptr<IEntity> &entity) const
    {
        auto components = entity->getFilteredComponents({IComponent::Type::CUBE, IComponent::Type::POSITION});
        auto cube = Component::castComponent<Cube>(components[0]);
        auto pos = Component::castComponent<Position>(components[1]);
        Vector3 position = {pos->x, pos->y, pos->z};

        Shape3D::drawCube(position, cube->getSize(), cube->getColor());
    }

    void GraphicSystem::displayText(std::shared_ptr<IEntity> &entity) const
    {
        auto components = entity->getFilteredComponents({IComponent::Type::TEXT, IComponent::Type::POSITION});
        auto text = Component::castComponent<String>(components[0]);
        auto pos = Component::castComponent<Position>(components[1]);

        _texts.at(text->getValue()).first->draw(pos->x, pos->y, text->getFontSize(), BLUE);
    }

    void GraphicSystem::loadText(std::shared_ptr<IEntity> &entity)
    {
        auto text = Component::castComponent<String>((*entity)[IComponent::Type::TEXT]);

        if (_texts.find(text->getValue()) != _texts.end())
            _texts[text->getValue()].second++;
        else
            _texts[text->getValue()] = std::make_pair(std::make_unique<Text>(text->getValue(), text->getFontFile()), 1);
    }

    void GraphicSystem::unloadText(std::shared_ptr<IEntity> &entity)
    {
        auto text = Component::castComponent<String>((*entity)[IComponent::Type::TEXT]);

        if (_texts[text->getValue()].second != 1)
            _texts[text->getValue()].second--;
        else
            _texts.erase(text->getValue());
    }
}