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

#include "Position.hpp"
#include "Sprite.hpp"
#include "Core.hpp"
#include "Entity.hpp"
#include "EventListener.hpp"
#include "Scene.hpp"
#include "String.hpp"
#include "MusicComponent.hpp"
#include "SoundComponent.hpp"
#include "AudioDevice.hpp"

namespace indie
{

    void GameSystem::init(indie::SceneManager &sceneManager)
    {
        std::cout << "GameSystem::init" << std::endl;

        sceneManager.addScene(createScene(), SceneManager::SceneType::GAME);
        sceneManager.setCurrentScene(SceneManager::SceneType::GAME);
        // indie::AudioDevice audioDevice;
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
        std::shared_ptr<Entity> entity = std::make_shared<Entity>();
        std::shared_ptr<Entity> musicEntity = std::make_shared<Entity>();
        std::shared_ptr<Position> component = std::make_shared<Position>(10, 10);
        std::shared_ptr<String> component2 = std::make_shared<String>("sprite");
        std::shared_ptr<String> component3 = std::make_shared<String>("vector");
        std::shared_ptr<Sprite> component4 = std::make_shared<Sprite>("test_pictures/raylib_logo.png");
        std::shared_ptr<MusicComponent> musicComponent = std::make_shared<MusicComponent>("music.ogg");

        component2->setType(Component::Type::TEXT);
        component3->setType(Component::Type::HITBOX);
        std::shared_ptr<EventListener> listener = std::make_shared<EventListener>();

        ButtonCallbacks spaceCallbacks(
            [musicEntity](SceneManager &) {
                auto comp = Component::castComponent<MusicComponent>((*musicEntity)[Component::Type::MUSIC]);
                if (comp->getMusicState() == Music::MusicState::PAUSE)
                    comp->setMusicState(Music::MusicState::PLAY);
                else
                    comp->setMusicState(Music::MusicState::PAUSE);
            },
            [](SceneManager &) {},
            [](SceneManager &) {});

        listener->addKeyboardEvent(KEY_SPACE, spaceCallbacks);

        musicEntity->addComponent(component)
            .addComponent(component4)
            .addComponent(musicComponent)
            .addComponent(listener);
        entity->addComponent(component2)
            .addComponent(component3);

        scene->addEntities({entity, musicEntity});
        return scene;
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
