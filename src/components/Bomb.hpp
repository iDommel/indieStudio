/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "Component.hpp"

namespace indie {

class Bomb: public Component{
    public:
        Bomb(int blastPower = 1);
        ~Bomb();

        void explode();
    protected:
    private:
        int _seconds;
        int _blastPower;
        bool _isActive;
};

}
#endif /* !BOMB_HPP_ */
