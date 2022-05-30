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

        /**
         * @brief Inits the scene by calling its init function
         * @return Returns the new scene's ptr
         */
        virtual std::unique_ptr<IScene> initScene() = 0;

        /**
         * @brief Get entities with correcponding tags
         * @param tags Tags to search for
         * @return Returns a vector of entities
         */
        virtual std::vector<std::shared_ptr<IEntity>> getTaggedEntities(std::vector<IEntity::Tags> tags) = 0;
    };
}

#endif /* ISCENE_HPP */