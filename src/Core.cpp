/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Core.cpp
*/

#include <chrono>

#include "Core.hpp"
#include "systems/GameSystem.hpp"
#include "systems/AudioSystem.hpp"
#include "systems/GraphicSystem.hpp"
#include "systems/EventSystem.hpp"

namespace indie {

    Core::Core()
    {
        _systems[SystemType::GRAPHIC] = std::make_unique<GraphicSystem>();
        _systems[SystemType::AUDIO] = std::make_unique<AudioSystem>();
        _systems[SystemType::GAME] = std::make_unique<GameSystem>();
        _systems[SystemType::EVENT] = std::make_unique<EventSystem>();
    }

    void Core::mainLoop()
    {
        auto clock = std::chrono::high_resolution_clock::now();

        for (auto &system : _systems)
            system.second->init(_sceneManager);

        _sceneManager.setAddEntityCallback(std::bind(&Core::loadEntity, this, std::placeholders::_1));

        while (!_end) {
            auto time  = std::chrono::high_resolution_clock::now();
            auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(time - clock).count();
            if (deltaTime < UPDATE_DELTA)
                continue;
            _systems[SystemType::EVENT]->update(_sceneManager, deltaTime);
            _systems[SystemType::GAME]->update(_sceneManager, deltaTime);
            _systems[SystemType::GRAPHIC]->update(_sceneManager, deltaTime);
            _systems[SystemType::AUDIO]->update(_sceneManager, deltaTime);
            _end = true;
        }
        for (auto &system : _systems)
            system.second->destroy();
    }

    void Core::loadEntity(std::shared_ptr<IEntity> entity)
    {
        for (auto &system : _systems)
            system.second->loadEntity(entity);
    }

}
