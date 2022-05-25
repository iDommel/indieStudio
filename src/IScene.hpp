/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Scene.hpp
*/

#ifndef ISCENE_HPP
#define ISCENE_HPP

#include <vector>
#include <memory>

#include "IEntity.hpp"

namespace indie {
    class IScene
    {
    public:

        virtual std::vector<std::shared_ptr<IEntity>> &getEntities() = 0;
        virtual void addEntity(std::shared_ptr<IEntity> entity) = 0;
        virtual void removeEntity(std::shared_ptr<IEntity> entity) = 0;
    };
}

#endif /* ISCENE_HPP */