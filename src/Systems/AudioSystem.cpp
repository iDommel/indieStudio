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
        std::cout << "AudioSystem::update" << std::endl;
        for (auto &e : sceneManager.getCurrentScene().getEntities()) {
            if (e->hasTag(IEntity::Tags::AUDIBLE))
                std::cout << "play sound" << std::endl;
        }
    }

    void AudioSystem::destroy()
    {
        std::cout << "AudioSystem::destroy" << std::endl;
    }

}