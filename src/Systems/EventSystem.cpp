/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** EventSystem.cpp
*/

#include <iostream>

#include "EventSystem.hpp"

namespace indie {

    void EventSystem::init(SceneManager &)
    {
        std::cout << "EventSystem init" << std::endl;
    }

    void EventSystem::update(SceneManager &sceneManager, uint64_t)
    {
        for (auto &e : sceneManager.getCurrentScene().getEntities()) {
            if (e->hasTag(IEntity::Tags::CALLABLE))
                std::cout << "call event handler" << std::endl;
        }
    }

    void EventSystem::destroy()
    {
        std::cout << "EventSystem destroy" << std::endl;
    }

    void EventSystem::loadEntity(std::shared_ptr<IEntity> entity)
    {
        std::cout << "EventSystem::loadEntity" << std::endl;
    }

}