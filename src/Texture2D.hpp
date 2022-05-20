/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Texture2D
*/

#ifndef TEXTURE2D_HPP_
#define TEXTURE2D_HPP_

#include <iostream>

namespace indie {
    class Texture {
        public:
            Texture();
            ~Texture();

            void LoadTexture(const std::string &fileName);
            void UnloadTexture();
            void DrawTexture(int posX, int posY, Color tint);
        protected:
        private:
            Texture2D _texture;
    };
}
#endif /* !TEXTURE2D_HPP_ */
