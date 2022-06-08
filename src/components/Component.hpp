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
        Component(const Type &type): _type(type) {};
        
        Type getType() const;

        template <typename T>
        static std::shared_ptr<T> castComponent(std::shared_ptr<IComponent> &component)
        {
            std::shared_ptr<T> res = std::dynamic_pointer_cast<T>(component);

            if (res == nullptr)
                throw std::runtime_error("Component: dynamic_pointer_cast failed");
            return res;
        }

    protected:
        Type _type;
    };
}

#endif /* COMPONENT_HPP */