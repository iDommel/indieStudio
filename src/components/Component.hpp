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
        Type getType() const override;

        void setType(Type type) { _type = type; };

        bool isInitialized() const override { return _isInitialized; };

        /**
         * @brief Try casting the component to the given type
         * @tparam T type expected
         * @param component IComponent to try cast
         * @return std::shared_ptr<T> casted component or null shared_ptr if cast failed
         */
        template <typename T>
        static std::shared_ptr<T> castComponent(std::shared_ptr<IComponent> &component)
        {
            return std::dynamic_pointer_cast<T>(component);
        }

    protected:
        Type _type = Type::TYPE_NB;
        bool _isInitialized = false;
    };
}

#endif /* COMPONENT_HPP */