/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** AudioSystem.cpp
*/

#include <iostream>
#include "raylib.h"

#include "AudioSystem.hpp"
#include "Sound.hpp"
#include "Music.hpp"
#include "Component.hpp"
#include "MusicComponent.hpp"
#include "AudioDevice.hpp"

namespace indie
{

    void AudioSystem::init(SceneManager &SceneManager)
    {
        std::cout << "AudioSystem::init" << std::endl;
        indie::AudioDevice audioDevice;
        _musics.emplace(std::string("music.ogg"), std::make_unique<Music>("resources/Music.ogg"));
        //_sounds.emplace(std::string("sound_det"), std::make_unique<Sound>("resources/Detonation.ogg"));
        //_sounds.emplace(std::string("sound_expl"), std::make_unique<Sound>("resources/Explosion.ogg"));
    }

    void AudioSystem::update(SceneManager &sceneManager, uint64_t)
    {
        for (auto &e: sceneManager.getCurrentScene()[IEntity::Tags::AUDIBLE]) {
            for (auto musicComponent: e->getFilteredComponents({IComponent::Type::MUSIC})) {
                auto music = Component::castComponent<MusicComponent>(musicComponent);
                manageMusic(*music);
            }
            //for (auto soundComponent: e->getFilteredComponents({IComponent::Type::SOUND})) {
            //    auto sound = Component::castComponent<SoundComponent>(soundComponent);
            //    manageSound(*sound);
            //}
        }
    }

    void AudioSystem::destroy()
    {
        std::cout << "AudioSystem::destroy" << std::endl;
    }

    void AudioSystem::loadEntity(std::shared_ptr<IEntity> entity)
    {
        std::cout << "AudioSystem::loadEntity" << std::endl;
        if (entity->hasTag(IEntity::Tags::AUDIBLE)) {
            std::cout << "AudioSystem::loadEntity" << std::endl;
        }
    }

    void AudioSystem::unloadEntity(std::shared_ptr<IEntity>)
    {
        std::cout << "AudioSystem::unloadEntity" << std::endl;
    }

    void AudioSystem::manageMusic(MusicComponent &musicComponent)
    {
        if (musicComponent._newState == _musics[musicComponent.music]->_state)
            return;
        std::cout << "AudioSystem::manageMusic" << std::endl;
        if (musicComponent._newState == Music::MusicState::PLAY) {
            _musics[musicComponent.music]->playMusic();
        }
        else if (musicComponent._newState == Music::MusicState::PAUSE)
            _musics[musicComponent.music]->pauseMusic();
        else if (musicComponent._newState == Music::MusicState::STOP)
            _musics[musicComponent.music]->stopMusic();
        _musics[musicComponent.music]->_state = musicComponent._newState;
    }

    //void AudioSystem::manageSound(SoundComponent &soundComponent)
    //{
    //    if (soundComponent._newState == _sounds[soundComponent.sound]->_state)
    //        return;
    //    std::cout << "AudioSystem::manageSound" << std::endl;
    //    if (soundComponent._newState == Sound::SoundState::PLAYING)
    //        _sounds[soundComponent.sound]->play();
    //    else if (soundComponent._newState == Sound::SoundState::PAUSED)
    //        _sounds[soundComponent.sound]->pause();
    //    else if (soundComponent._newState == Sound::SoundState::STOPPED)
    //        _sounds[soundComponent.sound]->stop();
    //    _sounds[soundComponent.sound]->_state = soundComponent._newState;
    //}
}