/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** SoundComponent
*/

#ifndef SOUNDCOMPONENT_HPP_
#define SOUNDCOMPONENT_HPP_

#include <string>
#include "Component.hpp"
#include "Sound.hpp"

namespace indie
{
    class SoundComponent : public Component
    {
    public:
        SoundComponent(std::string str) : Component(Type::SOUND), sound(str) {};

        std::string getValue() const { return sound; };
        void setSoundState(Sound::SoundState state) { _newState = state; };
        Sound::SoundState getSoundState() { return _newState; };

    private:
        Sound::SoundState _newState = Sound::SoundState::PLAYING;
        std::string sound;
    };
}

#endif /* !SOUNDCOMPONENT_HPP_ */
