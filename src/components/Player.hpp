/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Component.hpp"
#include "EventListener.hpp"
#include "SceneManager.hpp"

namespace indie
{
    class Velocity;

    class Player : public Component
    {
    public:
        enum class Keys {
            UP,
            DOWN,
            LEFT,
            RIGHT,
            BOMB
        };

        Player(int id);
        ~Player();

        ///@brief Handle the various bonuses
        void handleBonus();
        /**
         * @brief Generate a bomb and add it to the entities list
         * @param manager The scene manager
         */
        void generateBomb(SceneManager &manager, std::shared_ptr<IEntity> entity);

        ///@brief gets the player ID
        int getId() const;

        ///@brief gets the current player speed
        int getSpeed() const;

        ///@brief gets the current maximum number of bomb a player can drop
        int getNbBomb() const;

        /// @brief sets the velocity of the player to its speed value to the right
        void moveRight(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT);
        /// @brief sets the velocity of the player to 0 to the right
        void stopRight(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT);
        /// @brief sets the velocity of the player to its speed value to the left
        void moveLeft(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT);
        /// @brief sets the velocity of the player to 0 to the left
        void stopLeft(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT);
        /// @brief sets the velocity of the player to its speed value upwards
        void moveUp(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT);
        /// @brief sets the velocity of the player to 0 upwards
        void stopUp(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT);
        /// @brief sets the velocity of the player to its speed value downwards
        void moveDown(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT);
        /// @brief sets the velocity of the player to 0 downwards
        void stopDown(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT);

    protected:
    private:
        void move(std::shared_ptr<Velocity> vel);
        int _nbBomb;
        int _blastPower;
        int _speed;
        int _id;
        bool _isUp;
        bool _isDown;
        bool _isLeft;
        bool _isRight;
        static const int _defaultSpeed = 40;
        static const int _defaultNbBomb = 3;
        static const int _defaultBlastPower = 3;
    };

}

#endif /* !PLAYER_HPP_ */
