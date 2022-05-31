/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** AudioSystem.cpp
*/

#include <iostream>

#include "AudioSystem.hpp"

namespace indie {

    void AudioSystem::init(SceneManager &)
    {
        std::cout << "AudioSystem::init" << std::endl;
    }

    void AudioSystem::update(SceneManager &sceneManager, uint64_t)
    {
        for (auto &e : sceneManager.getCurrentScene().getEntities()) {
            if (e->hasTag(IEntity::Tags::AUDIBLE))
                std::cout << "play audio" << std::endl;
        }
    }

    void AudioSystem::destroy()
    {
        std::cout << "AudioSystem::destroy" << std::endl;
    }

    void AudioSystem::loadEntity(std::shared_ptr<IEntity> entity)
    {
        std::cout << "AudioSystem::loadEntity" << std::endl;
    }

}