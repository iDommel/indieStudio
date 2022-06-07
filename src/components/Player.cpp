/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Player
*/

#include "Player.hpp"

#include <raylib.h>

#include <functional>

#include "ButtonCallbacks.hpp"
#include "Entity.hpp"
#include "Position.hpp"
#include "String.hpp"

namespace indie
{

    Player::Player(std::map<Keys, KeyboardKey>, int id) : Component(Type::PLAYER), _id(id)
    {
        _nbBomb = 1;
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

    void Player::moveRight(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT)
    {
        auto pos = Component::castComponent<Position>((*entity)[Component::Type::POSITION]);
        pos->x += dT * 0.1;
        std::cout << "Player :" << _id << std::endl;
        std::cout << "Player::moveRight" << std::endl;
        std::cout << "pos->x = " << pos->x << std::endl;
        std::cout << "pos->y = " << pos->y << std::endl;
        std::cout << "pos->z = " << pos->z << std::endl;
    }

    void Player::moveLeft(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT)
    {
        auto pos = Component::castComponent<Position>((*entity)[Component::Type::POSITION]);
        pos->x -= dT * 0.1;
        std::cout << "Player :" << _id << std::endl;
        std::cout << "Player::moveLeft" << std::endl;
        std::cout << "pos->x = " << pos->x << std::endl;
        std::cout << "pos->y = " << pos->y << std::endl;
        std::cout << "pos->z = " << pos->z << std::endl;
    }

    void Player::moveUp(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT)
    {
        auto pos = Component::castComponent<Position>((*entity)[Component::Type::POSITION]);
        pos->y -= dT * 0.1;
        std::cout << "Player :" << _id << std::endl;
        std::cout << "Player::moveUp" << std::endl;
        std::cout << "pos->x = " << pos->x << std::endl;
        std::cout << "pos->y = " << pos->y << std::endl;
        std::cout << "pos->z = " << pos->z << std::endl;
    }

    void Player::moveDown(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT)
    {
        auto pos = Component::castComponent<Position>((*entity)[Component::Type::POSITION]);

        pos->y += dT * 0.1;
        std::cout << "Player :" << _id << std::endl;
        std::cout << "Player::moveDown" << std::endl;
        std::cout << "pos->x = " << pos->x << std::endl;
        std::cout << "pos->y = " << pos->y << std::endl;
        std::cout << "pos->z = " << pos->z << std::endl;
    }

}
