/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** AudioSystem.hpp
*/

#ifndef AUDIO_SYSTEM_HPP
#define AUDIO_SYSTEM_HPP

#include "System.hpp"
#include "../Scene.hpp"

namespace Indie {

    class AudioSystem : public ISystem
    {
    public:

        void init(SceneManager &manager) final override;
        void update(SceneManager &manager) final override;
        void destroy() final override;

    private:
    };

}

#endif /* AUDIO_SYSTEM_HPP */