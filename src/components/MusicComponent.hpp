/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Music
*/

#ifndef MUSICCOMPONENT_HPP_
#define MUSICCOMPONENT_HPP_

#include <string>
#include "Component.hpp"
#include "Music.hpp"

namespace indie
{

    class MusicComponent : public Component
    {
    public:
        MusicComponent(std::string str) : music(str) { _type = IComponent::Type::MUSIC; };

        std::string getValue() const { return music; };
        Music::MusicState _newState = Music::MusicState::PLAY;
        std::string music;

    private:
    };

}

#endif /* !MUSIC_HPP_ */
