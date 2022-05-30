/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Scene.cpp
*/

#include <algorithm>

#include "Scene.hpp"

namespace indie
{

    Scene::Scene(std::function<std::unique_ptr<IScene>()> init, std::function<void(std::shared_ptr<IEntity>)> addEntityCallback)
        : _initFunc(init), _addEntityCallback(addEntityCallback) {}

    std::vector<std::shared_ptr<IEntity>> &Scene::getEntities()
    {
        return _entities;
    }

    void Scene::addEntity(std::shared_ptr<IEntity> entity)
    {
        _entities.push_back(entity);
        _addEntityCallback(entity);
    }

    void Scene::removeEntity(std::shared_ptr<IEntity> entity)
    {
        auto it = std::find(_entities.begin(), _entities.end(), entity);

        if (it == _entities.end())
            return;
        _entities.erase(it);
    }

    std::unique_ptr<IScene> Scene::initScene()
    {
        return _initFunc();
    }

    std::vector<std::shared_ptr<IEntity>> Scene::getTaggedEntities(std::vector<IEntity::Tags> tags)
    {
        std::vector<std::shared_ptr<IEntity>> taggedEntities;
        bool hasTags = true;

        for (auto &entity : _entities) {
            for (auto &tag : tags) {
                if (!entity->hasTag(tag)) {
                    hasTags = false;
                    break;
                }
            }
            if (!hasTags)
                continue;
            taggedEntities.push_back(entity);
        }
        return taggedEntities;
    }

}