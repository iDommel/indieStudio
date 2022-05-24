/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** System.hpp
*/

#ifndef SYSTEM_HPP
#define SYSTEM_HPP

namespace Indie {

    class SceneManager;

    class ISystem
    {
    public:
        virtual void init(SceneManager &manager) = 0;
        virtual void update(SceneManager &manager) = 0;
        virtual void destroy() = 0;
    };

}

#endif /* SYSTEM_HPP */