/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** player
*/

#ifndef AIPLAYER_HPP_
#define AIPLAYER_HPP_

#include "Component.hpp"
#include "EventListener.hpp"
#include "SceneManager.hpp"

namespace indie
{
    class Velocity;

    class AIPlayer : public Component
    {
    public:

        AIPlayer(int id);

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

        void setRadar(std::shared_ptr<IEntity> radar);
        std::shared_ptr<IEntity> getRadar() const;

    protected:
    private:
        void move(std::shared_ptr<Velocity> vel);
        size_t _nbBombMax = 3;
        int _blastPower = 3;
        int _speed = 60;
        int _id;
        std::vector<std::shared_ptr<IEntity>> _bombs;
        std::shared_ptr<IEntity> _radar;
    };

}

#endif /* !PLAYER_HPP_ */
