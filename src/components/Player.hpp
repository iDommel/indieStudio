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

namespace indie {

class Player: public Component {
    public:
        enum class Keys {
            UP,
            DOWN,
            LEFT,
            RIGHT,
            BOMB
        };

        Player(/*std::map<Keys, KeyboardKey> binds*/);
        ~Player();

        ///@brief Handle the various bonuses
        void handleBonus();

        /**
         * @brief Generate a bomb and add it to the entities list
         * @param manager The scene manager
         */
        void generateBomb(SceneManager &manager);

    protected:
    private:
        int _nbBomb;
        int _blastPower;
        EventListener _eventListener;
        Type _type;
};

}

#endif /* !PLAYER_HPP_ */
