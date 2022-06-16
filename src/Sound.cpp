/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Sound.cpp
*/

#include "raylib.h"
#include <iostream>

#include "Sound.hpp"
#include "exceptions/SoundError.hpp"

namespace indie
{

    Sound::Sound(const std::string &filename)
    {
        _sound = std::make_unique<::Sound>();
        *_sound = LoadSound(filename.c_str());
        if (_sound->frameCount == 0)
            throw SoundError("Sound file not found");
    }

    Sound::~Sound()
    {
        if (!_sound)
            return;
        UnloadSound(*_sound);
        delete _sound.release();
    }

    void Sound::play()
    {
        if (IsSoundPlaying(*_sound) == false)
            _state = SoundState::STOPPED;
        PlaySoundMulti(*_sound);
        _state = SoundState::PLAYING;
    }

    void Sound::stop()
    {
        if (_state == SoundState::STOPPED)
            return;
        StopSound(*_sound);
        _state = SoundState::STOPPED;
    }

    void Sound::pause()
    {
        if (_state == SoundState::PAUSED || _state == SoundState::STOPPED)
            return;
        PauseSound(*_sound);
        _state = SoundState::PAUSED;
    }

    void Sound::resume()
    {
        if (_state != SoundState::PAUSED)
            return;
        ResumeSound(*_sound);
        _state = SoundState::PLAYING;
    }

    Sound::SoundState Sound::getState() const
    {
        return _state;
    }

    void Sound::setVolume(float volume)
    {
        SetSoundVolume(*_sound, volume);
    }

}
