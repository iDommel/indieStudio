/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** AudioSystem.hpp
*/

#ifndef AUDIO_SYSTEM_HPP
#define AUDIO_SYSTEM_HPP

#include "ISystem.hpp"
#include "../SceneManager.hpp"

namespace indie {

    class AudioSystem : public ISystem
    {
    public:

        void init(SceneManager &manager) final override;
        void update(SceneManager &manager, uint64_t deltaTime) final override;
        void destroy() final override;

    private:
    };

}

#endif /* AUDIO_SYSTEM_HPP */