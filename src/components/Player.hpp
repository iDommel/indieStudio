/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** player
*/

#ifndef PLAYHER_H
    #define PLAYHER_H

    #include "Component.hpp"

    namespace indie {
        class Player : public Component {
            public:
                Player(std::string _up, std::string _down, std::string _left, std::string _right, std::string _bomb) : 
                UP(_up), DOWN(_down), LEFT(_left), RIGHT(_right), BOMB(_bomb) { _type = Type::PLAYER; }
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
                std::string UP;
                std::string DOWN;
                std::string LEFT;
                std::string RIGHT;
                std::string BOMB;
        };
    }

#endif /* !PLAYHER_H */
