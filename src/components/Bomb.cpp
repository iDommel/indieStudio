/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Bomb
*/

#include <iostream>
#include "Bomb.hpp"

namespace indie {

Bomb::Bomb(int blastPower)
{
    _type = Type::BOMB;
    _blastPower = blastPower;
    _countdown = 2;
}

Bomb::~Bomb()
{
}

void Bomb::setTimer(uint64_t seconds)
{
    _countdown = seconds;
}

uint64_t Bomb::getTimer() const
{
    return _countdown;
}

void Bomb::explode()
{
    std::cout << "---------------------------Bomb exploded" << std::endl;
}

}
