/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** EventSystem.hpp
*/

#ifndef EVENT_SYSTEM_HPP
#define EVENT_SYSTEM_HPP

#include "../SceneManager.hpp"
#include "ISystem.hpp"

namespace indie
{
    class EventListener;
    class EventSystem : public ISystem
    {
    public:
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
        void handleKeyboard(std::shared_ptr<EventListener> listener);
        void handleMouse(std::shared_ptr<EventListener> listener);
        void handleGamepad(std::shared_ptr<EventListener> listener, int nb);
        void handleGamepadSticks(std::shared_ptr<EventListener> listener, int nb);
    };

}

#endif /* EVENT_SYSTEM_HPP */