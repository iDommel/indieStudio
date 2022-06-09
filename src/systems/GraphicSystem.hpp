/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GraphicSystem.hpp
*/

#ifndef GRAPHIC_SYSTEM_HPP
#define GRAPHIC_SYSTEM_HPP

#include "ISystem.hpp"
#include "SceneManager.hpp"
#include "Window.hpp"
#include "Texture2D.hpp"
#include "Model.hpp"
#include "Text.hpp"

namespace indie
{

    class GraphicSystem : public ISystem
    {
    public:
        GraphicSystem();
        void init(SceneManager &manager) final;
        void update(SceneManager &manager, uint64_t deltaTime) final;
        void destroy() final;

        /**
         * @brief The callback to be called when an entity is added to a scene
         * @param entity The Entity that was added
         */
        void loadEntity(std::shared_ptr<IEntity> entity) final;
        /**
         * @brief The callback to be called when an entity is removed from a scene
         * @param entity The Entity that was removed
         */
        void unloadEntity(std::shared_ptr<IEntity> entity) final;

    private:
        /// @brief Adds a sprite to the cache
        void loadSprite(std::shared_ptr<IEntity> &entity);
        /// @brief Removes a model to the cache
        void unloadSprite(std::shared_ptr<IEntity> &entity);
        /// @brief Displays a model
        void displaySprite(std::shared_ptr<IEntity> &entity) const;

        /// @brief Adds a model to the cache
        void loadModel(std::shared_ptr<IEntity> &entity);
        /// @brief Removes a model from the cache
        void unloadModel(std::shared_ptr<IEntity> &entity);
        /// @brief Displays a model
        void displayModel(std::shared_ptr<IEntity> &entity) const;

        /// @brief Displays a grid
        void displayGrid(std::shared_ptr<IEntity> &entity) const;
        /// @brief Displays a sphere
        void displaySphere(std::shared_ptr<IEntity> &entity) const;
        /// @brief Displays a cube
        void displayCube(std::shared_ptr<IEntity> &entity) const;

        /// @brief Adds a text to the cache
        void loadText(std::shared_ptr<IEntity> &entity);
        /// @brief Removes a text from the cache
        void unloadText(std::shared_ptr<IEntity> &entity);
        /// @brief Displays a text
        void displayText(std::shared_ptr<IEntity> &entity) const;

        std::unique_ptr<Window> _window;
        std::map<std::string, std::pair<std::unique_ptr<Texture>, int>> _textures;
        std::map<std::string, std::pair<std::unique_ptr<Model>, int>> _models;
        std::map<std::string, std::pair<std::unique_ptr<Text>, int>> _texts;
    };

}

#endif /* GRAPHIC_SYSTEM_HPP */