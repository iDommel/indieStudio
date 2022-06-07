/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GameSystem.cpp
*/

#include "GameSystem.hpp"

#include <functional>
#include <iostream>

#include "Core.hpp"
#include "Entity.hpp"
#include "EventListener.hpp"
#include "Player.hpp"
#include "Position.hpp"
#include "Scene.hpp"
#include "Sprite.hpp"
#include "String.hpp"
#include "Velocity.hpp"
#include "raylib.h"
namespace indie
{

    void GameSystem::init(indie::SceneManager &sceneManager)
    {
        std::cout << "GameSystem::init" << std::endl;

        sceneManager.addScene(createScene(), SceneManager::SceneType::GAME);
        sceneManager.setCurrentScene(SceneManager::SceneType::GAME);
    }

    void GameSystem::update(indie::SceneManager &sceneManager, uint64_t)
    {
        static int i = 0;
        // std::cout << "GameSystem::update" << std::endl;
        // auto e = sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D][0];
        // auto comp = (*e)[Component::Type::SPRITE];
        i++;
        if (i == 100) {
            std::shared_ptr<Entity> entity = std::make_shared<Entity>();
            std::shared_ptr<Position> component = std::make_shared<Position>(500, 100);
            std::shared_ptr<Sprite> component4 = std::make_shared<Sprite>("test_pictures/raylib_logo.png");
            entity->addComponent(component).addComponent(component4);
            sceneManager.getCurrentScene().addEntity(entity);
        } else if (i == 200) {
            sceneManager.getCurrentScene().removeEntity(sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D][1]);
        }
    }

    void GameSystem::destroy()
    {
        std::cout << "GameSystem::destroy" << std::endl;
    }

    std::unique_ptr<indie::IScene> GameSystem::createScene()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createScene, this));
        std::shared_ptr<Entity> spriteEntity = std::make_shared<Entity>();
        std::shared_ptr<Position> pos = std::make_shared<Position>(10, 10);
        std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>("test_pictures/raylib_logo.png");

        spriteEntity->addComponent(pos)
            .addComponent(sprite);
        createPlayer(*scene, KEY_RIGHT, KEY_LEFT, KEY_UP, KEY_DOWN, 1);
        createPlayer(*scene, KEY_A, KEY_D, KEY_W, KEY_S, 2);
        scene->addEntities({spriteEntity});
        return scene;
    }

    void GameSystem::createPlayer(Scene &scene, int keyRight, int keyLeft, int keyUp, int keyDown, int id)
    {
        std::shared_ptr<Entity> playerEntity = std::make_shared<Entity>();
        std::shared_ptr<Position> playerPos = std::make_shared<Position>(10, 10);
        std::shared_ptr<Velocity> playerVel = std::make_shared<Velocity>(0, 0);
        std::shared_ptr<Player> player = std::make_shared<Player>(std::map<Player::Keys, KeyboardKey>(), id);
        std::shared_ptr<EventListener> playerListener = std::make_shared<EventListener>();

        ButtonCallbacks moveRightCallbacks(
            std::bind(&Player::moveRight, *player, std::placeholders::_1, playerEntity, 17),
            nullptr,
            nullptr);
        ButtonCallbacks moveLeftCallbacks(
            std::bind(&Player::moveLeft, *player, std::placeholders::_1, playerEntity, 17),
            nullptr,
            nullptr);
        ButtonCallbacks moveUpCallbacks(
            std::bind(&Player::moveUp, *player, std::placeholders::_1, playerEntity, 17),
            nullptr,
            nullptr);
        ButtonCallbacks moveDownCallbacks(
            std::bind(&Player::moveDown, *player, std::placeholders::_1, playerEntity, 17),
            nullptr,
            nullptr);
        playerListener->addKeyboardEvent((KeyboardKey)keyRight, moveRightCallbacks);
        playerListener->addKeyboardEvent((KeyboardKey)keyLeft, moveLeftCallbacks);
        playerListener->addKeyboardEvent((KeyboardKey)keyDown, moveDownCallbacks);
        playerListener->addKeyboardEvent((KeyboardKey)keyUp, moveUpCallbacks);

        playerEntity->addComponent(player)
            .addComponent(playerPos)
            .addComponent(playerVel)
            .addComponent(playerListener);
        scene.addEntity(playerEntity);
    }

    void GameSystem::loadEntity(std::shared_ptr<IEntity>)
    {
    }

    void GameSystem::unloadEntity(std::shared_ptr<IEntity>)
    {
    }

    void GameSystem::printStuff(SceneManager &)
    {
        std::cout << "GameSystem::printStuff" << std::endl;
    }
}