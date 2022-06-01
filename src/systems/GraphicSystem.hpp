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

    private:
        std::unique_ptr<Window> _window;
    };

}

#endif /* GRAPHIC_SYSTEM_HPP */