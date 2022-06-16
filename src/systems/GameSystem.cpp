/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GameSystem.cpp
*/

#include "GameSystem.hpp"

#include <functional>
#include <iostream>

#include "CameraComponent.hpp"
#include "Core.hpp"
#include "Entity.hpp"
#include "EventListener.hpp"
#include "Grid.hpp"
#include "HitboxComponent.hpp"
#include "Model3D.hpp"
#include "Player.hpp"
#include "Position.hpp"
#include "Rect.hpp"
#include "Scene.hpp"
#include "Sprite.hpp"
#include "String.hpp"
#include "Velocity.hpp"
#include "Bomb.hpp"
#include "Timer.hpp"
#include "Destructible.hpp"
#include "CameraComponent.hpp"
#include "ModelAnim.hpp"
#include "Window.hpp"
#include "raylib.h"
namespace indie
{

    void GameSystem::init(indie::SceneManager &sceneManager)
    {
        std::cout << "GameSystem::init" << std::endl;

        sceneManager.addScene(createScene(), SceneManager::SceneType::GAME);
        sceneManager.setCurrentScene(SceneManager::SceneType::GAME);
        _collideSystem.init(sceneManager);
    }

    void GameSystem::update(indie::SceneManager &sceneManager, uint64_t dt)
    {
        updatePlayers(sceneManager, dt);
        updateBombs(sceneManager, dt);
        _collideSystem.update(sceneManager, dt);
        auto renderables = sceneManager.getCurrentScene()[IEntity::Tags::RENDERABLE_3D];
        for (auto &renderable : renderables) {
            if (renderable->hasComponent({IComponent::Type::ANIMATION})) {
                auto component = Component::castComponent<ModelAnim>((*renderable)[IComponent::Type::ANIMATION]);
                component->getCurrentFrame()++;
                if (component->getCurrentFrame() >= component->getNbFrames())
                    component->getCurrentFrame() = 0;
            }
        }
    }

    void GameSystem::destroy()
    {
        std::cout << "GameSystem::destroy" << std::endl;
        _collideSystem.destroy();
    }

    std::shared_ptr<IEntity> GameSystem::createCamera(Vector3 camPos, Vector3 camTarget)
    {
        std::shared_ptr<Entity> cam = std::make_shared<Entity>();
        std::shared_ptr<CameraComponent> camera = std::make_shared<CameraComponent>(camTarget, camPos);

        cam->addComponent(camera);
        return cam;
    }

    void GameSystem::updatePlayers(SceneManager &sceneManager, uint64_t dt)
    {
        auto players = sceneManager.getCurrentScene()[IEntity::Tags::PLAYER];
        for (auto &player : players) {
            auto pos = Component::castComponent<Position>((*player)[IComponent::Type::POSITION]);
            auto lastPos = *pos;
            auto vel = Component::castComponent<Velocity>((*player)[IComponent::Type::VELOCITY]);
            auto playerComp = Component::castComponent<Player>((*player)[IComponent::Type::PLAYER]);
            auto hitbox = Component::castComponent<Hitbox>((*player)[IComponent::Type::HITBOX]);

            (*pos) = *pos + (*vel * (float)(dt / 1000.0f));
            (*hitbox) += *vel * (float)(dt / 1000.0f);
            if (!_collideSystem.getColliders(player).empty()) {
                (*pos) = lastPos;
                (*hitbox) -= *vel * (float)(dt / 1000.0f);
            }
        }
    }

    void GameSystem::updateBombs(SceneManager &sceneManager, uint64_t dt)
    {
        auto bombs = sceneManager.getCurrentScene()[IEntity::Tags::BOMB];
        auto explosions = sceneManager.getCurrentScene()[IEntity::Tags::TIMED];

        for (auto &bomb : bombs) {
            auto comp = Component::castComponent<Bomb>((*bomb)[IComponent::Type::BOMB]);
            auto pos = Component::castComponent<Position>((*bomb)[IComponent::Type::POSITION]);
            Vector3 vec = {pos->x, pos->y, pos->z};
            comp->setTimer(comp->getTimer() - dt);
            if (comp->getTimer() <= 0) {
                comp->explode(sceneManager, vec);
                sceneManager.getCurrentScene().removeEntity(bomb);
            }
        }

        for (auto &explosion : explosions) {
            auto comp = Component::castComponent<Timer>((*explosion)[IComponent::Type::TIMER]);
            comp->getTime() -= dt;
            if (comp->getTime() <= 0) {
                sceneManager.getCurrentScene().removeEntity(explosion);
                continue;
            }

            for (auto &collider : _collideSystem.getColliders(explosion)) {
                if (collider->hasTag(IEntity::Tags::DESTRUCTIBLE))
                    sceneManager.getCurrentScene().removeEntity(collider);
                else if (collider->hasTag(IEntity::Tags::BOMB)) {
                    auto bombComp = Component::castComponent<Bomb>((*collider)[IComponent::Type::BOMB]);
                    auto pos = Component::castComponent<Position>((*collider)[IComponent::Type::POSITION]);
                    bombComp->explode(sceneManager, {pos->x, pos->y, pos->z});
                }
            }
        }
    }

    std::unique_ptr<IScene> GameSystem::createScene()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createScene, this));

        std::shared_ptr<Entity> modelEntity = std::make_shared<Entity>();
        std::shared_ptr<Position> pos2 = std::make_shared<Position>(20, 0, 20);
        std::shared_ptr<Model3D> model = std::make_shared<Model3D>("assets_test/guy.iqm", "assets_test/guytex.png");
        std::shared_ptr<ModelAnim> anim = std::make_shared<ModelAnim>("assets_test/guyanim.iqm");
        std::shared_ptr<Hitbox> hitbox = std::make_shared<Hitbox>(true);
        modelEntity->addComponent(pos2)
            .addComponent(model)
            .addComponent(anim)
            .addComponent(hitbox);

        createPlayer(*scene, KEY_RIGHT, KEY_LEFT, KEY_UP, KEY_DOWN, KEY_END, 1, {10, 0, 10});
        createPlayer(*scene, KEY_D, KEY_A, KEY_W, KEY_S, KEY_E, 2, {0, 0, 0});
        scene->addEntities({modelEntity, createCamera({50.0f, 50.0f, 50.0f}, {0.0f, 10.0f, 0.0f})});
        return scene;
    }

    void GameSystem::createPlayer(Scene &scene, int keyRight, int keyLeft, int keyUp, int keyDown, int keyBomb, int id, Position pos)
    {
        std::shared_ptr<Entity> playerEntity = std::make_shared<Entity>();
        std::shared_ptr<Position> playerPos = std::make_shared<Position>(pos);
        std::shared_ptr<Velocity> playerVel = std::make_shared<Velocity>(0, 0);
        std::shared_ptr<Hitbox> playerHitbox = std::make_shared<Hitbox>(true);
        std::shared_ptr<Model3D> model = std::make_shared<Model3D>("test_models/turret.obj", "test_models/turret_diffuse.png");
        std::shared_ptr<Player> player = std::make_shared<Player>(id);
        std::shared_ptr<EventListener> playerListener = std::make_shared<EventListener>();
        std::shared_ptr<Destructible> destruct = std::make_shared<Destructible>();

        ButtonCallbacks moveRightCallbacks(
            [player, playerEntity](SceneManager &manager) {
                player->moveRight(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopRight(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->moveRight(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopRight(manager, playerEntity, 1);
            });
        ButtonCallbacks moveLeftCallbacks(
            [player, playerEntity](SceneManager &manager) {
                player->moveLeft(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopLeft(manager, playerEntity, 17);
            },
            [player, playerEntity](SceneManager &manager) {
                player->moveLeft(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopLeft(manager, playerEntity, 17);
            });
        ButtonCallbacks moveUpCallbacks(
            [player, playerEntity](SceneManager &manager) {
                player->moveUp(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopUp(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->moveUp(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopUp(manager, playerEntity, 1);
            });
        ButtonCallbacks moveDownCallbacks(
            [player, playerEntity](SceneManager &manager) {
                player->moveDown(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopDown(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->moveDown(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopDown(manager, playerEntity, 1);
            });
        ButtonCallbacks bombCallbacks(
            [player, playerEntity](SceneManager &manager) {
                player->generateBomb(manager, playerEntity);
            },
            [player, playerEntity](SceneManager &) {},
            [player, playerEntity](SceneManager &) {},
            [player, playerEntity](SceneManager &) {});
        playerListener->addKeyboardEvent((KeyboardKey)keyUp, moveUpCallbacks);
        playerListener->addKeyboardEvent((KeyboardKey)keyLeft, moveLeftCallbacks);
        playerListener->addKeyboardEvent((KeyboardKey)keyRight, moveRightCallbacks);
        playerListener->addKeyboardEvent((KeyboardKey)keyDown, moveDownCallbacks);
        playerListener->addKeyboardEvent((KeyboardKey)keyBomb, bombCallbacks);

        playerEntity->addComponent(player)
            .addComponent(playerPos)
            .addComponent(playerVel)
            .addComponent(playerListener)
            .addComponent(playerHitbox)
            .addComponent(model)
            .addComponent(destruct);
        scene.addEntity(playerEntity);
    }

    void GameSystem::loadEntity(std::shared_ptr<IEntity> entity)
    {
        _collideSystem.loadEntity(entity);
    }

    void GameSystem::unloadEntity(std::shared_ptr<IEntity> entity)
    {
        _collideSystem.unloadEntity(entity);
    }

    void GameSystem::printStuff(SceneManager &)
    {
        std::cout << "GameSystem::printStuff" << std::endl;
    }
}