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

namespace Indie {

    Core::Core()
    {
        _systems[SystemType::GRAPHIC] = std::make_unique<GraphicSystem>();
        _systems[SystemType::AUDIO] = std::make_unique<AudioSystem>();
        _systems[SystemType::GAME] = std::make_unique<GameSystem>();
    }

    void Core::mainLoop()
    {

    }

}