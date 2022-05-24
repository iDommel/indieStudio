/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Scene.hpp
*/

#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <memory>

#include "Entity.hpp"

namespace Indie {
    class Scene
    {
    public:
        std::vector<std::shared_ptr<Entity>> &getEntities();

    private:
        std::vector<std::shared_ptr<Entity>> _entities;
    };
}

#endif /* SCENE_HPP */