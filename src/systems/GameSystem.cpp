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
#include "CameraComponent.hpp"
<<<<<<< HEAD
#include "SoundComponent.hpp"
#include "MusicComponent.hpp"
=======
#include "ModelAnim.hpp"
#include "Window.hpp"
>>>>>>> origin/dev
#include "raylib.h"
namespace indie
{

    void GameSystem::init(indie::SceneManager &sceneManager)
    {
        std::cout << "GameSystem::init" << std::endl;

        sceneManager.addScene(createScene(), SceneManager::SceneType::GAME);
        sceneManager.setCurrentScene(SceneManager::SceneType::GAME);
<<<<<<< HEAD
        // indie::AudioDevice audioDevice;
=======
        _collideSystem.init(sceneManager);
>>>>>>> origin/dev
    }

    void GameSystem::update(indie::SceneManager &sceneManager, uint64_t dt)
    {
        static int i = 0;
        static int j = 0;

        i++;
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
    }

    void GameSystem::destroy()
    {
        std::cout << "GameSystem::destroy" << std::endl;
        _collideSystem.destroy();
    }

    std::shared_ptr<IEntity> GameSystem::createCamera(Vector3 camPos, Vector3 camTarget)
    {
<<<<<<< HEAD
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createScene, this));
        std::shared_ptr<Entity> entity2 = std::make_shared<Entity>();
        std::shared_ptr<Position> component = std::make_shared<Position>(10, 10);
        std::shared_ptr<Sprite> component4 = std::make_shared<Sprite>("test_pictures/raylib_logo.png");
        std::shared_ptr<MusicComponent> musicComponent = std::make_shared<MusicComponent>("music.ogg");
        std::shared_ptr<SoundComponent> soundComponent = std::make_shared<SoundComponent>("sound_det");
        std::shared_ptr<SoundComponent> soundComponent2 = std::make_shared<SoundComponent>("sound_expl");
        std::shared_ptr<Rect> component5 = std::make_shared<Rect>(0, 0, 250, 250);
        std::shared_ptr<Component> component3 = std::make_shared<Component>();
        std::shared_ptr<Entity> e = std::make_shared<Entity>();
        std::shared_ptr<Rect> rect  = std::make_shared<Rect>(0, 0, 0, 0);
        std::shared_ptr<Position> pos = std::make_shared<Position>(500, 500);
        std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>("test_pictures/scarfy.png", 6);
        std::shared_ptr<Entity> e2 = std::make_shared<Entity>();
        std::shared_ptr<Position> pos2 = std::make_shared<Position>(0, 0, 0);
        std::shared_ptr<Model3D> model = std::make_shared<Model3D>("test_models/turret.obj", "test_models/turret_diffuse.png");

=======
>>>>>>> origin/dev
        std::shared_ptr<Entity> cam = std::make_shared<Entity>();
        std::shared_ptr<CameraComponent> camera = std::make_shared<CameraComponent>(camTarget, camPos);

<<<<<<< HEAD
        std::shared_ptr<Entity> e3 = std::make_shared<Entity>();
        std::shared_ptr<Position> pos3 = std::make_shared<Position>(10, 0, 0);
        std::shared_ptr<String> text = std::make_shared<String>("The below sprite entity has a hitbox of 250,250");

        std::shared_ptr<Entity> e4 = std::make_shared<Entity>();
        std::shared_ptr<Position> pos4 = std::make_shared<Position>(0, 0, 0);
        std::shared_ptr<Grid> grid = std::make_shared<Grid>(10, 1.0f);
        std::shared_ptr<Entity> soundEntity = std::make_shared<Entity>();
        std::shared_ptr<Entity> soundEntity2 = std::make_shared<Entity>();

        std::shared_ptr<EventListener> listener = std::make_shared<EventListener>();

        soundEntity->addComponent(soundComponent)
            .addComponent(listener);

        soundEntity2->addComponent(soundComponent2)
            .addComponent(listener);
        
        ButtonCallbacks spaceCallbacks(
            [soundEntity2](SceneManager &) {
                auto comp = Component::castComponent<SoundComponent>((*soundEntity2)[Component::Type::SOUND]);
                if (comp->getSoundState() == Sound::SoundState::PLAYING)
                    comp->setSoundState(Sound::SoundState::PAUSED);
                else
                    comp->setSoundState(Sound::SoundState::PLAYING);
            },
            [](SceneManager &) {},
            [](SceneManager &) {});

        listener->addKeyboardEvent(KEY_SPACE, spaceCallbacks);
        component3->setType(Component::Type::HITBOX);

        entity2->addComponent(component)
            .addComponent(component4)
            .addComponent(component3)
            .addComponent(component5);

        e->addComponent(rect)
            .addComponent(pos)
            .addComponent(sprite);

        e2->addComponent(pos2)
            .addComponent(model);

=======
>>>>>>> origin/dev
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

<<<<<<< HEAD
        scene->addEntities({entity2, e, e2, cam, e3, e4, soundEntity});
=======
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

        createPlayer(*scene, KEY_RIGHT, KEY_LEFT, KEY_UP, KEY_DOWN, 1, {10, 0, 10});
        createPlayer(*scene, KEY_D, KEY_A, KEY_W, KEY_S, 2, {0, 0, 0});
        scene->addEntities({modelEntity, createCamera({50.0f, 50.0f, 50.0f}, {0.0f, 10.0f, 0.0f})});
>>>>>>> origin/dev
        return scene;
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
        playerListener->addKeyboardEvent((KeyboardKey)keyUp, moveUpCallbacks);
        playerListener->addKeyboardEvent((KeyboardKey)keyLeft, moveLeftCallbacks);
        playerListener->addKeyboardEvent((KeyboardKey)keyRight, moveRightCallbacks);
        playerListener->addKeyboardEvent((KeyboardKey)keyDown, moveDownCallbacks);

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
