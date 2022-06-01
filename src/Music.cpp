/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Music
*/

#include "raylib.h"

#include "Music.hpp"
#include "exceptions/MusicError.hpp"

namespace indie {
    Music::Music(const std::string &fileName)
    {
        _music = std::make_unique<::Music>();
        *_music = LoadMusicStream(fileName.c_str());
        if (_music->frameCount == 0)
            throw MusicError("Music file not found");
    }

    Music::~Music()
    {
        if (!_music)
            return;
        UnloadMusicStream(*_music);
        delete _music.release();
    }

    void Music::PlayMusic()
    {
        if (IsMusicStreamPlaying(*_music) == false)
            _state = MusicState::STOP;
        PlayMusicStream(*_music);
        _state = MusicState::PLAY;
    }

    void Music::StopMusic()
    {
        if (_state == MusicState::STOP)
            return;
        StopMusicStream(*_music);
        _state = MusicState::STOP;
    }

    void Music::PauseMusic()
    {
        if (_state == MusicState::PAUSE)
            return;
        PauseMusicStream(*_music);
        _state = MusicState::PAUSE;
    }

    void Music::ResumeMusic()
    {
        if (_state != MusicState::PAUSE)
            return;
        ResumeMusicStream(*_music);
        _state = MusicState::PLAY;
    }

    void Music::MusicVolume(float volume)
    {
        SetMusicVolume(*_music, volume);
    }

    void Music::UpdateMusic()
    {
        UpdateMusicStream(*_music);
    }

    float Music::MusicTimeLength()
    {
        return GetMusicTimeLength(*_music);
    }

    float Music::MusicTimePlayed()
    {
        return GetMusicTimePlayed(*_music);
    }
}