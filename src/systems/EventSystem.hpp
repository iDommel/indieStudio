/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** EventSystem.hpp
*/

#ifndef EVENT_SYSTEM_HPP
#define EVENT_SYSTEM_HPP

#include "ISystem.hpp"
#include "../SceneManager.hpp"

namespace indie {

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

    private:
    };

}

#endif /* EVENT_SYSTEM_HPP */