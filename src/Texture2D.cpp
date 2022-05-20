/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Texture2D
*/


#include <raylib.h>
#include "Texture2D.hpp"

namespace indie {

Texture::Texture(const std::string &fileName)
{
    _texture = std::make_unique<Texture2D>(::LoadTexture(fileName.c_str()));
    _isLoaded = true;
}

Texture::~Texture()
{
    if (_isLoaded)
        UnloadTexture();
}

void Texture::LoadTexture(const std::string &fileName)
{
    if (_isLoaded)
        UnloadTexture();
    _texture = std::make_unique<Texture2D>(::LoadTexture(fileName.c_str()));
    _isLoaded = true;
}

void Texture::UnloadTexture()
{
    if (_isLoaded) {
        ::UnloadTexture(*(_texture.get()));
        _isLoaded = false;
    }
}

int Texture::getWidth() const
{
    return _texture->width;
}

int Texture::getHeight() const
{
    return _texture->height;
}

void Texture::DrawTexture(int posX, int posY, Color tint = WHITE)
{
    if (_isLoaded)
        ::DrawTexture(*(_texture.get()), posX, posY, tint);
}

void Texture::DrawTexture(int posX, int posY)
{
    if (_isLoaded)
        ::DrawTexture(*(_texture.get()), posX, posY, WHITE);
}

void Texture::DrawTextureRec(Rectangle source, Vector2 position, Color tint = WHITE)
{
    if (_isLoaded)
        ::DrawTextureRec(*(_texture.get()), source, position, tint);
}

void Texture::DrawTextureRec(Rectangle source, Vector2 position)
{
    if (_isLoaded)
        ::DrawTextureRec(*(_texture.get()), source, position, WHITE);
}

void Texture::operator=(const Texture2D &other)
{
    if (_isLoaded)
        UnloadTexture();
    _texture = std::make_unique<Texture2D>(other);
}

}
