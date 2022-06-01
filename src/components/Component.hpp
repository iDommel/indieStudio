/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** AComponent.hpp
*/

#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <memory>

#include "IComponent.hpp"

namespace indie {

    class Component : public IComponent
    {
    public:

        Type getType() const;

        void setType(Type type) { _type = type; };

    protected:
        Type _type;
    };

}

#endif /* COMPONENT_HPP */