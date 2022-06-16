/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** AudioSystem.cpp
*/

#include "AudioSystem.hpp"

#include <iostream>

namespace indie
{

    void AudioSystem::init(SceneManager &)
    {
        std::cerr << "AudioSystem::init" << std::endl;
    }

    void AudioSystem::update(SceneManager &sceneManager, uint64_t)
    {
        for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::AUDIBLE]) {
            std::cerr << "play audio" << std::endl;
        }
    }

    void AudioSystem::destroy()
    {
        std::cerr << "AudioSystem::destroy" << std::endl;
    }

    void AudioSystem::loadEntity(std::shared_ptr<IEntity>)
    {
        std::cerr << "AudioSystem::loadEntity" << std::endl;
    }

    void AudioSystem::unloadEntity(std::shared_ptr<IEntity>)
    {
        std::cerr << "AudioSystem::unloadEntity" << std::endl;
    }

}