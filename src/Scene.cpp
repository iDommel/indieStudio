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
    std::vector<std::shared_ptr<IEntity>> &Scene::getEntities()
    {
        return _entities;
    }

    void Scene::addEntity(std::shared_ptr<IEntity> entity)
    {
        _entities.push_back(entity);
    }

    void Scene::removeEntity(std::shared_ptr<IEntity> entity)
    {
        auto it = std::find(_entities.begin(), _entities.end(), entity);

        if (it == _entities.end())
            return;
        _entities.erase(it);
    }

}