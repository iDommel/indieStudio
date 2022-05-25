/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** System.hpp
*/

#ifndef SYSTEM_HPP
#define SYSTEM_HPP

namespace indie {

    class SceneManager;

    class ISystem
    {
    public:
        virtual void init(SceneManager &manager) = 0;
        virtual void update(SceneManager &manager, uint64_t deltaTime) = 0;
        virtual void destroy() = 0;
    };

}

#endif /* SYSTEM_HPP */