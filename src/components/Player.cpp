/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Player
*/

#include <raylib.h>
#include "Player.hpp"
#include "Bomb.hpp"
#include "IEntity.hpp"

namespace indie {

Player::Player(std::map<Keys, KeyboardKey> binds)
{
    _nbBomb = 1;
    _eventListener.addKeyboardEvent(binds[Keys::BOMB], generateBomb);
}

Player::~Player()
{
}

void Player::getBonus(/*bonus*/)
{
    /*if (bonus == nbBomb)
        _nbBomb++;
    else if (bonus == blastPower)
        _blastPower++;*/
}

void Player::generateBomb(SceneManager &manager)
{
    std::shared_ptr<IEntity> bomb;
    
    bomb->addComponent(std::make_shared<Bomb>(_blastPower));
    manager.getCurrentScene().addEntity(bomb);
}

}
