/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** player
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

        Player(int id, std::string _up, std::string _down, std::string _left, std::string _right, std::string _bomb);
        ~Player();

        ///@brief Handle the various bonuses
        void handleBonus();
        /**
         * @brief Generate a bomb and add it to the entities list
         * @param manager The scene manager
         */
        void generateBomb(SceneManager &manager, std::shared_ptr<IEntity> entity);
        void updateBombsVec();

        ///@brief gets the player ID
        int getId() const;

        ///@brief gets the current player speed
        int getSpeed() const;

        ///@brief gets the current maximum number of bomb a player can drop
        int getNbBomb() const;
        ///@brief Sets the current maximum number of bomb a player can drop
        void setNbBomb(int newNbBomb);

        ///@brief gets the current blast power
        int getBlastPower() const;

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

        /// @brief horizontal movement for gamepad sticks
        void moveHorizontal(SceneManager &manager, std::shared_ptr<IEntity> entity, float value);
        /// @brief verticcal movement for gamepad sticks
        void moveVertical(SceneManager &manager, std::shared_ptr<IEntity> entity, float value);

        void kill() { _isDead = true; };
        bool isDead() const { return _isDead; }
        std::string getUp() { return UP; }
        std::string getDown() { return DOWN; }
        std::string getLeft() { return LEFT; }
        std::string getRight() { return RIGHT; }
        std::string getBomb() { return BOMB; }
        void setUP(std::string _up) { UP = _up; }
        void setDOWN(std::string _down) { DOWN = _down; }
        void setLEFT(std::string _left) { LEFT = _left; }
        void setRIGHT(std::string _right) { RIGHT = _right; }
        void setBOMB(std::string _bomb) { BOMB = _bomb; }

        int changeUp;
        int changeDown;
        int changeLeft;
        int changeRight;
        int changeBomb;

    protected:
    private:
        void move(std::shared_ptr<Velocity> vel);
        size_t _nbBombMax = 3;
        int _blastPower;
        int _speed;
        int _id;
        bool _isDead = false;
        bool _isUp = false;
        bool _isDown = false;
        bool _isLeft = false;
        bool _isRight = false;
        static const int _defaultSpeed = 60;
        static const int _defaultBlastPower = 3;
        std::string UP;
        std::string DOWN;
        std::string LEFT;
        std::string RIGHT;
        std::vector<std::shared_ptr<IEntity>> _bombs;
        std::string BOMB;
    };

}

#endif /* !PLAYER_HPP_ */
