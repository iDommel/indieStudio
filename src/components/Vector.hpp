/*
** EPITECH PROJECT, 2022
** indie
** File description:
** vector2
*/

#ifndef VECTORH
    #define VECTORH

    #include "Component.hpp"

    namespace indie {
        class Vector2 : public Component {
            public:
                Vector2(float _x, float _y) { _x = x; _y = y; }
                float getX() {return x;};
                float getY() {return y;};

            private:
                float x;
                float y;
        };
    }

#endif /* !VECTORH */
