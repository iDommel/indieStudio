/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GameSystem.cpp
*/

#include "raylib.h"
#include "GameSystem.hpp"

#include <functional>
#include <iostream>

#include "CameraComponent.hpp"
#include "GamepadStickCallbacks.hpp"
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
#include "Bonus.hpp"
#include "Model3D.hpp"
#include "Grid.hpp"
#include "Velocity.hpp"
#include "CameraComponent.hpp"
#include "SoundComponent.hpp"
#include "MusicComponent.hpp"
#include "ModelAnim.hpp"
#include "Window.hpp"
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
        /*static int i = 0;
        // std::cout << "GameSystem::update" << std::endl;
        // auto e = sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D][0];
        // auto comp = (*e)[Component::Type::SPRITE];
        static int i = 0;

        i++;
        if (i % 3 == 0) {
            auto components = sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D][1]->getFilteredComponents({ IComponent::Type::RECT });
            auto r = Component::castComponent<Rect>(components[0]);
            r->left = r->width * j;
            if (++j > 5)
                j = 0;
        }
        if (i == 100) {
            std::shared_ptr<Entity> entity = std::make_shared<Entity>();
            std::shared_ptr<Position> component = std::make_shared<Position>(500, 100);
            std::shared_ptr<Sprite> component4 = std::make_shared<Sprite>("test_pictures/raylib_logo.png");
            entity->addComponent(component).addComponent(component4);
            sceneManager.getCurrentScene().addEntity(entity);
        } else if (i == 200) {
            sceneManager.getCurrentScene().removeEntity(sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D][1]);
        }*/

        //Check if there is any bonus
        for (auto &bonus : sceneManager.getCurrentScene()[IEntity::Tags::BONUS]) {
            auto comp = Component::castComponent<Bonus>((*bonus)[IComponent::Type::BONUS]);
            std::cout << "Bonuuuuuuuss !!!!!" << std::endl;
        updatePlayers(sceneManager, dt);
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
        //sceneManager.getCurrentScene().removeEntity(sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D][2]);
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

    std::unique_ptr<IScene> GameSystem::createScene()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createScene, this));

        Vector3 camPos = {GAME_MAP_WIDTH * GAME_TILE_SIZE / 2 /* / 8 * 5 */, 250.0f, GAME_MAP_HEIGHT * GAME_TILE_SIZE};
        Vector3 camTarget = {GAME_MAP_WIDTH * GAME_TILE_SIZE / 2, 0.0f, GAME_MAP_HEIGHT * GAME_TILE_SIZE / 2};

        createMusic(*scene);
        createSound(*scene);
        createPlayer(*scene, KEY_RIGHT, KEY_LEFT, KEY_UP, KEY_DOWN, 1, {GAME_TILE_SIZE + 1, 0, GAME_TILE_SIZE + 1});
        createPlayer(*scene, KEY_D, KEY_A, KEY_W, KEY_S, 2, {-10, 0, -20});
        generateMap("assets/maps/map2.txt", *scene);
        scene->addEntities({createCamera(camPos, camTarget)});
        return scene;
    }

    void GameSystem::createMusic(Scene &scene)
    {
        std::shared_ptr<Entity> musicEntity = std::make_shared<Entity>();
        std::shared_ptr<MusicComponent> musicComponent = std::make_shared<MusicComponent>("music.ogg");

        std::shared_ptr<EventListener> listener = std::make_shared<EventListener>();
        listener->addKeyboardEvent(KEY_SPACE, spaceCallbacks);
        musicEntity->addComponent(musicComponent);
        scene.addEntities({musicEntity});
    }

    void GameSystem::createSound(Scene &scene)
    {
        std::shared_ptr<Entity> soundEntity = std::make_shared<Entity>();
        std::shared_ptr<Entity> soundEntity2 = std::make_shared<Entity>();
        std::shared_ptr<SoundComponent> soundComponent = std::make_shared<SoundComponent>("sound_det");
        std::shared_ptr<SoundComponent> soundComponent2 = std::make_shared<SoundComponent>("sound_expl");

        soundEntity->addComponent(soundComponent);
        scene.addEntities({soundEntity});

        soundEntity2->addComponent(soundComponent2);
        scene.addEntities({soundEntity2});
    }

    void GameSystem::createPlayer(Scene &scene, int keyRight, int keyLeft, int keyUp, int keyDown, int id, Position pos)
    {
        std::shared_ptr<Entity> playerEntity = std::make_shared<Entity>();
        std::shared_ptr<Position> playerPos = std::make_shared<Position>(pos);
        std::shared_ptr<Velocity> playerVel = std::make_shared<Velocity>(0, 0);
        std::shared_ptr<Hitbox> playerHitbox = std::make_shared<Hitbox>(true);
        std::shared_ptr<Model3D> model = std::make_shared<Model3D>("test_models/turret.obj", "test_models/turret_diffuse.png");
        std::shared_ptr<Player> player = std::make_shared<Player>(id);
        std::shared_ptr<EventListener> playerListener = std::make_shared<EventListener>();

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

        // GamepadStickCallbacks moveHorizontalStickCallbacks(
        //     [player, playerEntity](SceneManager &manager, float) {
        //         player->moveLeft(manager, playerEntity, 1);
        //     },
        //     [player, playerEntity](SceneManager &manager) {
        //         player->stopRight(manager, playerEntity, 1);
        //         player->stopLeft(manager, playerEntity, 1);
        //     },
        //     [player, playerEntity](SceneManager &manager, float) {
        //         player->moveRight(manager, playerEntity, 1);
        //     });
        // GamepadStickCallbacks moveVerticalStickCallbacks(
        //     [player, playerEntity](SceneManager &manager, float) {
        //         player->moveUp(manager, playerEntity, 1);
        //     },
        //     [player, playerEntity](SceneManager &manager) {
        //         player->stopDown(manager, playerEntity, 1);
        //         player->stopUp(manager, playerEntity, 1);
        //     },
        //     [player, playerEntity](SceneManager &manager, float) {
        //         player->moveDown(manager, playerEntity, 1);
        //     });
        playerListener->addKeyboardEvent((KeyboardKey)keyUp, moveUpCallbacks);
        playerListener->addKeyboardEvent((KeyboardKey)keyLeft, moveLeftCallbacks);
        playerListener->addKeyboardEvent((KeyboardKey)keyRight, moveRightCallbacks);
        playerListener->addKeyboardEvent((KeyboardKey)keyDown, moveDownCallbacks);
        playerListener->addGamepadEvent(id - 1, (GamepadButton)GAMEPAD_BUTTON_LEFT_FACE_UP, moveUpCallbacks);
        playerListener->addGamepadEvent(id - 1, (GamepadButton)GAMEPAD_BUTTON_LEFT_FACE_RIGHT, moveRightCallbacks);
        playerListener->addGamepadEvent(id - 1, (GamepadButton)GAMEPAD_BUTTON_LEFT_FACE_DOWN, moveDownCallbacks);
        playerListener->addGamepadEvent(id - 1, (GamepadButton)GAMEPAD_BUTTON_LEFT_FACE_LEFT, moveLeftCallbacks);
        // playerListener->addGamepadStickEvent(id - 1, GAMEPAD_AXIS_LEFT_X, moveHorizontalStickCallbacks);
        // playerListener->addGamepadStickEvent(id - 1, GAMEPAD_AXIS_LEFT_Y, moveVerticalStickCallbacks);

        playerEntity->addComponent(player)
            .addComponent(playerPos)
            .addComponent(playerVel)
            .addComponent(playerListener)
            .addComponent(playerHitbox)
            .addComponent(model);
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
