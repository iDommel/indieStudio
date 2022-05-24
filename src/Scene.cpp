/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Scene.cpp
*/

#include "Scene.hpp"

namespace Indie
{
    std::vector<std::shared_ptr<Entity>> &Scene::getEntities()
    {
        return _entities;
    }
}