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
        /**
         * @brief Get the scene's entities
         * @return Returns a reference of the scene's entities vector
         */
        virtual std::vector<std::shared_ptr<IEntity>> &getEntities() = 0;

        /// @brief Add entity to scene
        virtual void addEntity(std::shared_ptr<IEntity> entity) = 0;
        /// @brief Removes the given entity from scene
        virtual void removeEntity(std::shared_ptr<IEntity> entity) = 0;
    };
}

#endif /* ISCENE_HPP */