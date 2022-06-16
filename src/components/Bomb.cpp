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

#define BOMB_TIMER      2000
#define EXPLOSION_TIMER 1000

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
    std::cout << "BOUM" << std::endl;
    std::shared_ptr<Entity> explosion = std::make_shared<Entity>();
    std::shared_ptr<Entity> explosion2 = std::make_shared<Entity>();
    Vector3 exSize = {_blastPower * GAME_TILE_SIZE, 5.0f, GAME_TILE_SIZE};
    Vector3 exPos = {pos.x - (exSize.x - GAME_TILE_SIZE) / 2, pos.y, pos.z};
    Vector3 ex2Size = {GAME_TILE_SIZE, 5,  _blastPower * GAME_TILE_SIZE};
    Vector3 ex2Pos = {pos.x, pos.y, pos.z - (ex2Size.z - GAME_TILE_SIZE) / 2};

    auto c = std::make_shared<Hitbox>(CollideSystem::makeBBoxFromSizePos(exSize, exPos));
    auto timer = std::make_shared<Timer>(EXPLOSION_TIMER);
    auto c2 = std::make_shared<Hitbox>(CollideSystem::makeBBoxFromSizePos(ex2Size, ex2Pos));
    auto timer2 = std::make_shared<Timer>(EXPLOSION_TIMER);

    explosion->addComponent(c)
                .addComponent(timer);
    explosion2->addComponent(c2)
                .addComponent(timer2);
    sceneManager.getCurrentScene().addEntities({explosion, explosion2});
}

}