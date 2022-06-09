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

    void GameSystem::update(indie::SceneManager &sceneManager, uint64_t dt)
    {
        static int i = 0;
        // std::cout << "GameSystem::update" << std::endl;
        // auto e = sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D][0];
        // auto comp = (*e)[Component::Type::SPRITE];
        i++;
        if (i % 10 == 0)
            updatePlayers(sceneManager, dt);
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

    void GameSystem::updatePlayers(SceneManager &sceneManager, uint64_t dt)
    {
        auto players = sceneManager.getCurrentScene()[IEntity::Tags::PLAYER];
        for (auto &player : players) {
            auto pos = Component::castComponent<Position>((*player)[IComponent::Type::POSITION]);
            auto vel = Component::castComponent<Velocity>((*player)[IComponent::Type::VELOCITY]);
            auto playerComp = Component::castComponent<Player>((*player)[IComponent::Type::PLAYER]);

            (*pos) = *pos + (*vel * (float)(dt / 1000.0f));
            std::cout << "Player: " << playerComp->getId();
            std::cout << "Player::update" << std::endl;
            std::cout << "pos->x = " << pos->x << std::endl;
            std::cout << "pos->y = " << pos->y << std::endl;
            std::cout << "pos->z = " << pos->z << std::endl;
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
        std::shared_ptr<Player> player = std::make_shared<Player>(id);
        std::shared_ptr<EventListener> playerListener = std::make_shared<EventListener>();

        ButtonCallbacks moveRightCallbacks(
            [player, playerEntity](SceneManager &manager) {
                player->moveRight(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopRight(manager, playerEntity, 1);
            },
            nullptr);
        ButtonCallbacks moveLeftCallbacks(
            [player, playerEntity](SceneManager &manager) {
                player->moveLeft(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopLeft(manager, playerEntity, 17);
            },
            nullptr);
        ButtonCallbacks moveUpCallbacks(
            [player, playerEntity](SceneManager &manager) {
                player->moveUp(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopUp(manager, playerEntity, 1);
            },
            nullptr);
        ButtonCallbacks moveDownCallbacks(
            [player, playerEntity](SceneManager &manager) {
                player->moveDown(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopDown(manager, playerEntity, 1);
            },
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