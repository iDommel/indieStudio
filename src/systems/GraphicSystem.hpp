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
        void loadSprite(std::shared_ptr<IEntity> &entity);
        void unloadSprite(std::shared_ptr<IEntity> &entity);
        void displaySprite(std::shared_ptr<IEntity> &entity) const;

        std::unique_ptr<Window> _window;
        std::map<std::string, std::pair<std::unique_ptr<Texture>, int>> _textures;
    };

}

#endif /* GRAPHIC_SYSTEM_HPP */