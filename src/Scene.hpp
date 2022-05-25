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

#include "IScene.hpp"
#include "IEntity.hpp"

namespace indie {
    class Scene : public IScene
    {
    public:
        std::vector<std::shared_ptr<IEntity>> &getEntities();

        void addEntity(std::shared_ptr<IEntity> entity);
        void removeEntity(std::shared_ptr<IEntity> entity);

    protected:
        std::vector<std::shared_ptr<IEntity>> _entities;
    };
}

#endif /* SCENE_HPP */