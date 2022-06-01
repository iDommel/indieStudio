/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Sound.cpp
*/

#include "raylib.h"

#include "Sound.hpp"

namespace indie
{

    Sound::Sound(const std::string &filename)
    {
        _sound = std::make_unique<::Sound>();
        *_sound = LoadSound(filename.c_str());
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
        if (_state == SoundState::PLAYING)
            return;
        PlaySound(*_sound);
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

}
