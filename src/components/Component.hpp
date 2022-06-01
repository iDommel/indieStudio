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

    template <typename T>
    std::shared_ptr<T> castComponent(std::shared_ptr<IComponent> component);

}

#endif /* COMPONENT_HPP */