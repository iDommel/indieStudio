/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Player
*/
#include "raylib.h"
#include "Player.hpp"


#include <functional>

#include "ButtonCallbacks.hpp"
#include "Entity.hpp"
#include "Position.hpp"
#include "String.hpp"
#include "Velocity.hpp"
#include "HitboxComponent.hpp"

namespace indie
{

    Player::Player(int id, std::string _up, std::string _down, std::string _left, std::string _right) : Component(Type::PLAYER), _id(id), UP(_up), DOWN(_down), LEFT(_left), RIGHT(_right)
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
        _isRight = true;
        std::cout << "moveRight" << std::endl;
        move(vel);
    }

    void Player::stopRight(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        _isRight = false;
        std::cout << "stopLeft" << std::endl;
        move(vel);
    }

    void Player::moveLeft(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        _isLeft = true;
        move(vel);
    }

    void Player::stopLeft(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        _isLeft = false;
        move(vel);
    }

    void Player::moveUp(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        _isUp = true;
        move(vel);
    }

    void Player::stopUp(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        _isUp = false;
        move(vel);
    }

    void Player::moveDown(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        _isDown = true;
        move(vel);
    }

    void Player::stopDown(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        _isDown = false;
        move(vel);
    }

    void Player::move(std::shared_ptr<Velocity> vel)
    {
        vel->z = (_speed * _isDown) + (-_speed * _isUp);
        vel->x = (_speed * _isRight) + (-_speed * _isLeft);
        std::cout << "isDown: " << _isDown << std::endl;
        std::cout << "isUp: " << _isUp << std::endl;
        std::cout << "isRight: " << _isRight << std::endl;
        std::cout << "isLeft: " << _isLeft << std::endl;
        std::cout << "velocity: " << vel->x << " " << vel->y << " " << vel->z << std::endl;
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
