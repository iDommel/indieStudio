/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Bomb
*/

#include <iostream>
#include "Bomb.hpp"
#include "raylib.h"

#include "CollideSystem.hpp"
#include "GameSystem.hpp"
#include "Entity.hpp"
#include "HitboxComponent.hpp"
#include "Timer.hpp"
#include "ParticleCloud.hpp"
#include "SoundComponent.hpp"

#define BOMB_TIMER      3000
#define EXPLOSION_TIMER 500

namespace indie {

Bomb::Bomb(int blastPower): Component(Type::BOMB)
{
    _countdown = BOMB_TIMER;
    _blastPower = blastPower;
}

Bomb::~Bomb()
{
}

void Bomb::setTimer(uint64_t seconds)
{
    if (seconds > _countdown)
        _countdown = 0;
    else
        _countdown = seconds;
}

uint64_t Bomb::getTimer() const
{
    return _countdown;
}

static void createParticlesHorizontal(SceneManager &sceneManager, Vector3 pos, int blastPower)
{
    float range = (((blastPower - 2) * GAME_TILE_SIZE) + (GAME_TILE_SIZE / 2));

    pos.z -= (GAME_TILE_SIZE / 2);
    for (int i = GAME_TILE_SIZE; i > 0; i--) {
        Vector3 targetEast = {(pos.x + range), 5.0f, pos.z + i};
        Vector3 targetWest = {(pos.x - range), 5.0f, pos.z + i};
        Vector3 actualPos = {pos.x, 5.0f, pos.z + i};
        std::shared_ptr<Entity> boom1 = std::make_shared<Entity>();
        std::shared_ptr<Entity> boom2 = std::make_shared<Entity>();

        boom1->addComponent(std::make_shared<ParticleCloud>(targetEast, actualPos, 1, 2, -1, EXPLOSION_TIMER));
        boom2->addComponent(std::make_shared<ParticleCloud>(targetWest, actualPos, 1, 2, -1, EXPLOSION_TIMER));
        sceneManager.getCurrentScene().addEntities({boom1, boom2});
    }
}

static void createParticlesVertical(SceneManager &sceneManager, Vector3 pos, int blastPower)
{
    float range = (((blastPower - 2) * GAME_TILE_SIZE) + (GAME_TILE_SIZE / 2));

    pos.x -= (GAME_TILE_SIZE / 2);
    for (int i = GAME_TILE_SIZE; i > 0; i--) {
        Vector3 targetSouth = {pos.x + i, 5.0f, (pos.z + range)};
        Vector3 targetNorth = {pos.x + i, 5.0f, (pos.z - range)};
        Vector3 actualPos = {pos.x + i, 5.0f, pos.z};
        std::shared_ptr<Entity> boom1 = std::make_shared<Entity>();
        std::shared_ptr<Entity> boom2 = std::make_shared<Entity>();

        boom1->addComponent(std::make_shared<ParticleCloud>(targetSouth, actualPos, 1, 2, -1, EXPLOSION_TIMER));
        boom2->addComponent(std::make_shared<ParticleCloud>(targetNorth, actualPos, 1, 2, -1, EXPLOSION_TIMER));
        sceneManager.getCurrentScene().addEntities({boom1, boom2});
    }
}

void Bomb::explode(SceneManager &sceneManager, Vector3 pos)
{
    std::shared_ptr<Entity> explosion = std::make_shared<Entity>();
    std::shared_ptr<Entity> explosion2 = std::make_shared<Entity>();
    Vector3 exSize = {_blastPower * GAME_TILE_SIZE - 2, 5.0f, GAME_TILE_SIZE - 2};
    Vector3 exPos = {pos.x - (exSize.x - GAME_TILE_SIZE) / 2 - GAME_TILE_SIZE/2 + 1, pos.y, pos.z - GAME_TILE_SIZE/2 + 1};
    Vector3 ex2Size = {GAME_TILE_SIZE - 2, 5,  _blastPower * GAME_TILE_SIZE - 2};
    Vector3 ex2Pos = {pos.x - GAME_TILE_SIZE/2 + 1, pos.y, pos.z - (ex2Size.z - GAME_TILE_SIZE) / 2 - GAME_TILE_SIZE/2};
    std::shared_ptr<Entity> sonicBoom = std::make_shared<Entity>();
    auto c = std::make_shared<Hitbox>(CollideSystem::makeBBoxFromSizePos(exSize, exPos));
    auto timer = std::make_shared<Timer>(EXPLOSION_TIMER);
    auto c2 = std::make_shared<Hitbox>(CollideSystem::makeBBoxFromSizePos(ex2Size, ex2Pos));
    auto timer2 = std::make_shared<Timer>(EXPLOSION_TIMER);

    sonicBoom->addComponent(std::make_shared<SoundComponent>("sound_expl"));
    explosion->addComponents({c, timer});
    explosion2->addComponents({c2, timer2});
    sceneManager.getCurrentScene().addEntities({explosion, explosion2, sonicBoom});
    createParticlesHorizontal(sceneManager, pos, _blastPower);
    createParticlesVertical(sceneManager, pos, _blastPower);
}

}