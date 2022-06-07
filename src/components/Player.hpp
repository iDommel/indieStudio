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

        Player(std::map<Keys, KeyboardKey> binds, int id);
        ~Player();

        ///@brief Handle the various bonuses
        void handleBonus();

        void moveRight(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT);
        void stopRight(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT);
        void moveLeft(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT);
        void stopLeft(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT);
        void moveUp(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT);
        void stopUp(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT);
        void moveDown(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT);
        void stopDown(SceneManager &manager, std::shared_ptr<IEntity> entity, float dT);

    protected:
    private:
        int _nbBomb;
        int _blastPower;
        int _id;
    };

}

#endif /* !PLAYER_HPP_ */
