/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Core.cpp
*/

#include "Core.hpp"
#include "Systems/GameSystem.hpp"
#include "Systems/AudioSystem.hpp"
#include "Systems/GraphicSystem.hpp"

namespace indie {

    Core::Core()
    {
        _systems[SystemType::GRAPHIC] = std::make_unique<GraphicSystem>();
        _systems[SystemType::AUDIO] = std::make_unique<AudioSystem>();
        _systems[SystemType::GAME] = std::make_unique<GameSystem>();
    }

    void Core::mainLoop()
    {

        for (auto &system : _systems)
            system.second->init(_sceneManager);

        for (int i = 0; i < 5; i++) {
            for (auto &system : _systems)
                system.second->update(_sceneManager);
        }
        for (auto &system : _systems)
            system.second->destroy();
    }

}