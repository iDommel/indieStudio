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

        
        ///@brief Explode the bomb after a certain amount of time
        void explode();
        void setTimer(uint64_t time);
        uint64_t getTimer() const;
    protected:
    private:
        uint64_t _countdown;
        int _blastPower;
        Type _type;
};

}
#endif /* !BOMB_HPP_ */
