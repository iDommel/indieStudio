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

void Bomb::explode(SceneManager &sceneManager, Vector3 pos)
{
    std::shared_ptr<Entity> explosion = std::make_shared<Entity>();
    std::shared_ptr<Entity> explosion2 = std::make_shared<Entity>();
    Vector3 exSize = {_blastPower * GAME_TILE_SIZE - 2, 5.0f, GAME_TILE_SIZE - 2};
    Vector3 exPos = {pos.x - (exSize.x - GAME_TILE_SIZE) / 2 - GAME_TILE_SIZE/2 + 1, pos.y, pos.z - GAME_TILE_SIZE/2 + 1};
    Vector3 ex2Size = {GAME_TILE_SIZE - 2, 5,  _blastPower * GAME_TILE_SIZE - 2};
    Vector3 ex2Pos = {pos.x - GAME_TILE_SIZE/2 + 1, pos.y, pos.z - (ex2Size.z - GAME_TILE_SIZE) / 2 - GAME_TILE_SIZE/2};
    Vector3 targetSouth = {pos.x, 5.0f, pos.z + ((_blastPower - 2) * GAME_TILE_SIZE)};
    Vector3 targetNorth = {pos.x, 5.0f, pos.z - ((_blastPower - 2) * GAME_TILE_SIZE)};
    Vector3 targetEast = {pos.x + ((_blastPower - 2) * GAME_TILE_SIZE), 5.0f, pos.z};
    Vector3 targetWest = {pos.x - ((_blastPower - 2) * GAME_TILE_SIZE), 5.0f, pos.z};

    std::cout << "Blast power: " << _blastPower << std::endl;
    auto c = std::make_shared<Hitbox>(CollideSystem::makeBBoxFromSizePos(exSize, exPos));
    auto timer = std::make_shared<Timer>(EXPLOSION_TIMER);
    auto c2 = std::make_shared<Hitbox>(CollideSystem::makeBBoxFromSizePos(ex2Size, ex2Pos));
    auto timer2 = std::make_shared<Timer>(EXPLOSION_TIMER);

    std::shared_ptr<Entity> boom1 = std::make_shared<Entity>();
    boom1->addComponent(std::make_shared<ParticleCloud>(targetNorth, pos, 10, 2, -1, EXPLOSION_TIMER));
    std::shared_ptr<Entity> boom2 = std::make_shared<Entity>();
    boom2->addComponent(std::make_shared<ParticleCloud>(targetSouth, pos, 10, 2, -1, EXPLOSION_TIMER));
    std::shared_ptr<Entity> boom3 = std::make_shared<Entity>();
    boom3->addComponent(std::make_shared<ParticleCloud>(targetEast, pos, 10, 2, -1, EXPLOSION_TIMER));
    std::shared_ptr<Entity> boom4 = std::make_shared<Entity>();
    boom4->addComponent(std::make_shared<ParticleCloud>(targetWest, pos, 10, 2, -1, EXPLOSION_TIMER));

    explosion->addComponent(c)
                .addComponent(timer);
    explosion2->addComponent(c2)
                .addComponent(timer2);
    sceneManager.getCurrentScene().addEntities({explosion, explosion2, boom1, boom2, boom3, boom4});
}

}