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
#include <functional>

#include "IScene.hpp"
#include "IEntity.hpp"

namespace indie {
    class Scene : public IScene
    {
    public:

        /**
         * @brief Scene constructor
         * @param init Scene init function
         * @param addEntityCallback Callback function when adding entity
         */
        Scene(std::function<std::unique_ptr<IScene>()> init, std::function<void(std::shared_ptr<IEntity>)> addEntityCallback);

        /**
         * @brief Get the scene's entities
         * @return Returns a reference of the scene's entities vector
         */
        std::vector<std::shared_ptr<IEntity>> &getEntities();

        /// @brief Add entity to scene
        void addEntity(std::shared_ptr<IEntity> entity);
        /// @brief Removes the given entity from scene
        void removeEntity(std::shared_ptr<IEntity> entity);
        /**
         * @brief Inits the scene by calling its init function
         * @return Returns the new scene's ptr
         */
        std::unique_ptr<IScene> initScene();

        /**
         * @brief Get entities with correcponding tags
         * @param tags Tags to search for
         * @return Returns a vector of entities
         */
        std::vector<std::shared_ptr<IEntity>> getTaggedEntities(std::vector<IEntity::Tags> tags);

    protected:
        std::vector<std::shared_ptr<IEntity>> _entities;
        /// @brief Scene's init function; called by GameSystem::init & Scene::reloadScene
        std::function<std::unique_ptr<IScene>()> _initFunc;
        /// @brief Callback when an entity is added to the scene
        std::function<void(std::shared_ptr<IEntity>)> _addEntityCallback;
    };
}

#endif /* SCENE_HPP */