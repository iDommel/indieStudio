/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Texture2D
*/


#include <raylib.h>
#include "exceptions/TextureError.hpp"
#include "Texture2D.hpp"

namespace indie {

Texture::Texture(const std::string &fileName)
{
    _texture = std::make_unique<Texture2D>(::LoadTexture(fileName.c_str()));
    if (!_texture)
        throw TextureError("Texture constructor: Texture not loaded");
    _isLoaded = true;
}

Texture::~Texture()
{
    if (_isLoaded)
        unloadTexture();
}

void Texture::loadTexture(const std::string &fileName)
{
    if (_isLoaded)
        unloadTexture();
    _texture = std::make_unique<Texture2D>(::LoadTexture(fileName.c_str()));
    if (!_texture)
        throw TextureError("Texture failed to load");
    _isLoaded = true;
}

void Texture::unloadTexture()
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

void Texture::drawTexture(int posX, int posY, Color tint = WHITE)
{
    if (_isLoaded)
        ::DrawTexture(*(_texture.get()), posX, posY, tint);
}

void Texture::drawTexture(int posX, int posY)
{
    if (_isLoaded)
        ::DrawTexture(*(_texture.get()), posX, posY, WHITE);
}

void Texture::setRect(float x, float y, float width, float height)
{
    if (!_rect)
        _rect = std::make_unique<Rectangle>();
    _rect.get()->x = x;
    _rect.get()->y = y;
    _rect.get()->width = width;
    _rect.get()->height = height;
}

void Texture::moveRect(int frame)
{
    if (_rect)
        _rect.get()->x = (float)frame * (float)getRect().width;
}

::Rectangle Texture::getRect()
{
    return *(_rect.get());
}

void Texture::drawTextureRec(Vector2 position, Color tint = WHITE)
{
    if (_isLoaded)
        ::DrawTextureRec(*(_texture.get()), *(_rect.get()), position, tint);
}

void Texture::drawTextureRec(Vector2 position)
{
    if (_isLoaded)
        ::DrawTextureRec(*(_texture.get()), *(_rect.get()), position, WHITE);
}

void Texture::operator=(const Texture2D &other)
{
    if (_isLoaded)
        unloadTexture();
    _texture = std::make_unique<Texture2D>(other);
    if (!_texture)
        throw TextureError("Texture failed to load");
}

}
