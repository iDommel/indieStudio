/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Player
*/

#include "Player.hpp"

#include "raylib.h"

#include <functional>
#include <cmath>

#include "ButtonCallbacks.hpp"
#include "Entity.hpp"
#include "Position.hpp"
#include "String.hpp"
#include "Velocity.hpp"
#include "HitboxComponent.hpp"
#include "Bomb.hpp"
#include "Sphere.hpp"
#include "GameSystem.hpp"

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

    void Player::moveRight(SceneManager &, std::shared_ptr<IEntity> entity, float)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        _isRight = true;
        std::cout << "moveRight" << std::endl;
        move(vel);
    }

    void Player::stopRight(SceneManager &, std::shared_ptr<IEntity> entity, float)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        _isRight = false;
        std::cout << "stopLeft" << std::endl;
        move(vel);
    }

    void Player::moveLeft(SceneManager &, std::shared_ptr<IEntity> entity, float)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        _isLeft = true;
        move(vel);
    }

    void Player::stopLeft(SceneManager &, std::shared_ptr<IEntity> entity, float)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        _isLeft = false;
        move(vel);
    }

    void Player::moveUp(SceneManager &, std::shared_ptr<IEntity> entity, float)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        _isUp = true;
        move(vel);
    }

    void Player::stopUp(SceneManager &, std::shared_ptr<IEntity> entity, float)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        _isUp = false;
        move(vel);
    }

    void Player::moveDown(SceneManager &, std::shared_ptr<IEntity> entity, float)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        _isDown = true;
        move(vel);
    }

    void Player::stopDown(SceneManager &, std::shared_ptr<IEntity> entity, float)
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

    void Player::generateBomb(SceneManager &manager, std::shared_ptr<IEntity> entity)
    {
        std::shared_ptr<Entity> bomb = std::make_shared<Entity>();
        auto pos = Component::castComponent<Position>((*entity)[Component::Type::POSITION]);

        if (bomb) {
            bomb->addComponent(std::make_shared<Bomb>(_blastPower));
            bomb->addComponent(std::make_shared<Position>(std::roundf(pos->x / GAME_TILE_SIZE) * GAME_TILE_SIZE, pos->y, std::roundf(pos->z / GAME_TILE_SIZE) * GAME_TILE_SIZE));
            bomb->addComponent(std::make_shared<Sphere>(GAME_TILE_SIZE / 2, BLUE));
        }
        manager.getCurrentScene().addEntity(bomb);
    }
}
