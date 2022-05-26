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

        void init(SceneManager &manager) final override;
        void update(SceneManager &manager, uint64_t deltaTime) final override;
        void destroy() final override;

    private:
    };

}

#endif /* EVENT_SYSTEM_HPP */