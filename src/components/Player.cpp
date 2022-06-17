/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Player
*/
#include "raylib.h"
#include "Player.hpp"


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

    Player::Player(int id, std::string _up, std::string _down, std::string _left, std::string _right, std::string _bomb) : Component(Type::PLAYER), _id(id), UP(_up), DOWN(_down), LEFT(_left), RIGHT(_right), BOMB(_bomb)
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
        move(vel);
    }

    void Player::stopRight(SceneManager &, std::shared_ptr<IEntity> entity, float)
    {
        auto vel = Component::castComponent<Velocity>((*entity)[Component::Type::VELOCITY]);
        _isRight = false;
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
            Vector3 size = {GAME_TILE_SIZE, GAME_TILE_SIZE, GAME_TILE_SIZE};
            Vector3 bPos = {std::roundf(pos->x / GAME_TILE_SIZE) * GAME_TILE_SIZE - GAME_TILE_SIZE/2, pos->y, std::roundf(pos->z / GAME_TILE_SIZE) * GAME_TILE_SIZE - GAME_TILE_SIZE/2};
            bomb->addComponent(std::make_shared<Bomb>(_blastPower));
            bomb->addComponent(std::make_shared<Position>(std::roundf(pos->x / GAME_TILE_SIZE) * GAME_TILE_SIZE, pos->y, std::roundf(pos->z / GAME_TILE_SIZE) * GAME_TILE_SIZE));
            bomb->addComponent(std::make_shared<Sphere>(GAME_TILE_SIZE / 2, BLUE))
                .addComponent(std::make_shared<Hitbox>(CollideSystem::makeBBoxFromSizePos(size, bPos)));
        }
        manager.getCurrentScene().addEntity(bomb);
    }
}
