/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Texture2D
*/

#include "Texture2D.hpp"
#include <raylib.h>

namespace indie {

Texture::Texture()
{
}

Texture::~Texture()
{
}

void Texture::LoadTexture(const std::string &fileName)
{
    _texture = ::LoadTexture(fileName.c_str());
}

void Texture::UnloadTexture()
{
    ::UnloadTexture(_texture);
}

void Texture::DrawTexture(int posX, int posY, Color tint)
{
    ::DrawTexture(_texture, posX, posY, tint);
}

}
