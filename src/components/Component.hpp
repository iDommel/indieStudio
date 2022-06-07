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
        Component(Type type);
        Type getType() const;

        void setType(Type type) { _type = type; };
        template <typename T>
        static std::shared_ptr<T> castComponent(std::shared_ptr<IComponent> &component)
        {
            std::shared_ptr<T> res = std::dynamic_pointer_cast<T>(component);

            if (res == nullptr)
                throw std::runtime_error("Component: dynamic_pointer_cast failed");
            return res;
        }
        /**
         * @brief Set the Parent entity, to wich the component belongs to
         *
         * @param parent entity to wich the component belongs to
         */
        void setParent(std::shared_ptr<IEntity> &&parent);
        /// @brief Get the Parent entity, to wich the component belongs to
        std::shared_ptr<IEntity> getParent();

    protected:
        Type _type;
        std::shared_ptr<IEntity> _parent;
    };
}

#endif /* COMPONENT_HPP */