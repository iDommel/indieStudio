/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Player
*/

#include "Player.hpp"

#include "raylib.h"

#include <functional>

#include "ButtonCallbacks.hpp"
#include "Entity.hpp"
#include "Position.hpp"
#include "String.hpp"
#include "Velocity.hpp"
#include "HitboxComponent.hpp"

namespace indie
{

    Player::Player(int id) : Component(Type::PLAYER), _id(id)
    {
        _nbBomb = _defaultNbBomb;
        _blastPower = _defaultBlastPower;
        _speed = _defaultSpeed;
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
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        vel->x = _speed;
        std::cout << "Player :" << _id << std::endl;

        std::cout << "Player::moveRight" << std::endl;
        std::cout << "pos->x = " << vel->x << std::endl;
        std::cout << "pos->y = " << vel->y << std::endl;
        std::cout << "pos->z = " << vel->z << std::endl;
    }

    void Player::stopRight(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        if (vel->x == _speed)
            vel->x = 0;
        std::cout << "Player::stopRight" << std::endl;
        std::cout << "pos->x = " << vel->x << std::endl;
        std::cout << "pos->y = " << vel->y << std::endl;
        std::cout << "pos->z = " << vel->z << std::endl;
    }

    void Player::moveLeft(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        vel->x = -_speed;
        std::cout << "Player :" << _id << std::endl;

        std::cout << "Player::moveLeft" << std::endl;
        std::cout << "pos->x = " << vel->x << std::endl;
        std::cout << "pos->y = " << vel->y << std::endl;
        std::cout << "pos->z = " << vel->z << std::endl;
    }

    void Player::stopLeft(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        if (vel->x == -_speed)
            vel->x = 0;
        std::cout << "Player::stopLeft" << std::endl;
        std::cout << "pos->x = " << vel->x << std::endl;
        std::cout << "pos->y = " << vel->y << std::endl;
        std::cout << "pos->z = " << vel->z << std::endl;
    }

    void Player::moveUp(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        vel->z = -_speed;
        std::cout << "Player::moveUp" << std::endl;
        std::cout << "pos->x = " << vel->x << std::endl;
        std::cout << "pos->y = " << vel->y << std::endl;
        std::cout << "pos->z = " << vel->z << std::endl;
    }

    void Player::stopUp(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        if (vel->z == -_speed)
            vel->z = 0;
        std::cout << "Player::stopUp" << std::endl;
        std::cout << "pos->x = " << vel->x << std::endl;
        std::cout << "pos->y = " << vel->y << std::endl;
        std::cout << "pos->z = " << vel->z << std::endl;
    }

    void Player::moveDown(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        vel->z = _speed;
        std::cout << "Player::moveDown" << std::endl;
        std::cout << "pos->x = " << vel->x << std::endl;
        std::cout << "pos->y = " << vel->y << std::endl;
        std::cout << "pos->z = " << vel->z << std::endl;
    }

    void Player::stopDown(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        if (vel->z == _speed)
            vel->z = 0;
        std::cout << "Player::stopDown" << std::endl;
        std::cout << "pos->x = " << vel->x << std::endl;
        std::cout << "pos->y = " << vel->y << std::endl;
        std::cout << "pos->z = " << vel->z << std::endl;
    }

    int Player::getId() const
    {
        return _id;
    }

    int Player::getSpeed() const
    {
        return _speed;
    }

    int Player::getNbBomb() const
    {
        return _nbBomb;
    }
}
