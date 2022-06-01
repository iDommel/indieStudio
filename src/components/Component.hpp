/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** AComponent.hpp
*/

#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <memory>
#include <stdexcept>

#include "IComponent.hpp"

namespace indie
{

    class Component : public IComponent
    {
    public:
        Type getType() const;

        void setType(Type type) { _type = type; };

    protected:
        Type _type;
    };

    template <typename T>
    std::shared_ptr<T> castComponent(std::shared_ptr<IComponent> component)
    {
        std::shared_ptr<T> res = std::dynamic_pointer_cast<T>(component);

        if (res == nullptr)
            throw std::runtime_error("Component: dynamic_pointer_cast failed");
        return res;
    }

}

#endif /* COMPONENT_HPP */