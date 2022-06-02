/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Player
*/

#include <raylib.h>
#include <functional>

#include "Player.hpp"
#include "Bomb.hpp"
#include "IEntity.hpp"
#include "ButtonCallbacks.hpp"

namespace indie {

Player::Player(std::map<Keys, KeyboardKey> binds)
{
    ButtonCallbacks bombCB(std::bind(&Player::generateBomb, this, std::placeholders::_1), [](SceneManager &){}, [](SceneManager &){});

    _type = Type::PLAYER;
    _nbBomb = 1;
    _eventListener.addKeyboardEvent(binds[Keys::BOMB], bombCB);
}

Player::~Player()
{
}

void Player::handleBonus(/*bonus*/)
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
