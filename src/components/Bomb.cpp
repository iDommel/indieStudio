/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Bomb
*/

#include <iostream>
#include "Bomb.hpp"

#define BOMB_TIMER 2000

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

void Bomb::explode()
{
    std::cout << "---------------------------BOMB EXPLODEEEEEEEEEEEEEEEEEEEED" << std::endl;
}

}