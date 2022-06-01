/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** AComponent.cpp
*/

#include <stdexcept>
#include "Component.hpp"

namespace indie
{

    Component::Type Component::getType() const
    {
        return _type;
    }

    // template <typename T>
    // std::shared_ptr<T> Component::castComponent(std::shared_ptr<IComponent> component)
    // {
    //     std::shared_ptr<T> res = std::dynamic_pointer_cast<T>(component);

    //     if (res == nullptr)
    //         throw std::runtime_error("Component: dynamic_pointer_cast failed");
    //     return res;
    // }

}