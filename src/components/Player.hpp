/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "EventListener.hpp"
#include "SceneManager.hpp"

namespace indie {

enum class Keys {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    BOMB
};

class Player: public Component {
    public:
        Player(std::map<Keys, KeyboardKey> binds);
        ~Player();

        void getBonus();
        void generateBomb(SceneManager &manager);
    protected:
    private:
        int _nbBomb;
        int _blastPower;
        EventListener _eventListener;
};

}
#endif /* !PLAYER_HPP_ */
