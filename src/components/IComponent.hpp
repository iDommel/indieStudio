/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** IComponent.hpp
*/

#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP

namespace indie
{

    class IEntity;
    class IComponent
    {
    public:
        enum class Type {
            VECTOR,
            POSITION,
            VELOCITY,
            TRANSFORM,
            ROTATION,
            TEXT,
            SPRITE,
            MODEL,
            HITBOX,
            MUSIC,
            SOUND,
            EVT_LISTENER,
            PLAYER
        };
        /**
         * @brief Set the Parent entity, to wich the component belongs to
         *
         * @param parent entity to wich the component belongs to
         */
        virtual void setParent(std::shared_ptr<IEntity> &&parent) = 0;
        /// @brief Get the Parent entity, to wich the component belongs to
        virtual std::shared_ptr<IEntity> getParent() = 0;
        virtual Type getType() const = 0;
    };

}

#endif /* ICOMPONENT_HPP */