/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** AISystem.cpp
*/

#include "raylib.h"

#include "AISystem.hpp"
#include "SceneManager.hpp"
#include "GameSystem.hpp"

#include "Position.hpp"
#include "Velocity.hpp"
#include "HitboxComponent.hpp"
#include "AIPlayer.hpp"

namespace indie
{

    AISystem::AISystem(CollideSystem &collideSystem) : _collideSystem(collideSystem) {}

    void AISystem::init(SceneManager &)
    {
    }

    void AISystem::update(SceneManager &manager, uint64_t deltaTime)
    {
    }

    void AISystem::destroy()
    {
    }

    void AISystem::loadEntity(std::shared_ptr<IEntity>)
    {
    }

    void AISystem::unloadEntity(std::shared_ptr<IEntity>)
    {
    }

}