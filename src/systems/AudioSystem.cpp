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

    void AudioSystem::init(SceneManager &)
    {
        if (AudioDevice::isReady()) {
            AudioDevice::setVolume(100);
        }
        _musics.emplace(std::string("music.ogg"), std::make_unique<Music>("resources/Music.ogg"));
        _sounds.emplace(std::string("sound_det"), std::make_unique<Sound>("resources/Detonation.ogg"));
        _sounds.emplace(std::string("sound_expl"), std::make_unique<Sound>("resources/Explosion.ogg"));
    }

    void AudioSystem::update(SceneManager &sceneManager, uint64_t)
    {
        if (!AudioDevice::isReady())
            return;
        for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::AUDIBLE]) {
            if ((*e)[IComponent::Type::MUSIC] == nullptr)
                continue;
            auto music = Component::castComponent<MusicComponent>((*e)[IComponent::Type::MUSIC]);
            manageMusic(*music);
        }
        for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::AUDIBLE]) {
            if ((*e)[IComponent::Type::SOUND] == nullptr)
                continue;
            auto sound = Component::castComponent<SoundComponent>((*e)[IComponent::Type::SOUND]);
            manageSound(*sound);
        }
    }

    void AudioSystem::destroy()
    {
        std::cout << "AudioSystem::destroy" << std::endl;
    }

    void AudioSystem::loadEntity(std::shared_ptr<IEntity>entity)
    {
        std::cout << "AudioSystem::loadEntity" << std::endl;
        if (entity->hasTag(IEntity::Tags::AUDIBLE)) {
            std::cout << "AudioSystem::loadEntity" << std::endl;
        }
    }

    void AudioSystem::unloadEntity(std::shared_ptr<IEntity>)
    {
        // std::cout << "AudioSystem::unloadEntity" << std::endl;
    }

    void AudioSystem::manageMusic(MusicComponent &musicComponent)
    {
        _musics[musicComponent.getValue()]->updateMusic();
        if (musicComponent.getMusicState() == _musics[musicComponent.getValue()]->getMusic())
            return;
        std::cout << "AudioSystem::manageMusic" << std::endl;
        if (musicComponent.getMusicState() == Music::MusicState::PLAY) {
            _musics[musicComponent.getValue()]->playMusic();
        } else if (musicComponent.getMusicState() == Music::MusicState::PAUSE)
            _musics[musicComponent.getValue()]->pauseMusic();
        else if (musicComponent.getMusicState() == Music::MusicState::STOP)
            _musics[musicComponent.getValue()]->stopMusic();
        _musics[musicComponent.getValue()]->getMusic() = musicComponent.getMusicState();
    }

     void AudioSystem::manageSound(SoundComponent &soundComponent)
    {
         if (soundComponent.getSoundState() == _sounds[soundComponent.getValue()]->getSound())
             return;
         std::cout << "AudioSystem::manageSound" << std::endl;
         if (soundComponent.getSoundState() == Sound::SoundState::PLAYING)
             _sounds[soundComponent.getValue()]->play();
         else if (soundComponent.getSoundState() == Sound::SoundState::PAUSED)
             _sounds[soundComponent.getValue()]->pause();
         else if (soundComponent.getSoundState() == Sound::SoundState::STOPPED)
             _sounds[soundComponent.getValue()]->stop();
         _sounds[soundComponent.getValue()]->getSound() = soundComponent.getSoundState();
    }
}