/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Font
*/

#include <raylib.h>
#include "Font.hpp"

namespace indie {

Font::Font()
{
    _font = std::make_unique<::Font>(::GetFontDefault());
    _isLoaded = true;
}

Font::Font(const std::string &fileName)
{
    _font = std::make_unique<::Font>(::LoadFont(fileName.c_str()));
    _isLoaded = true;
}

Font::~Font()
{
    if (_isLoaded)
        UnloadFont();
}

::Font Font::GetFontDefault(void) const
{
    return ::GetFontDefault();
}

void Font::LoadFont(const std::string &fileName)
{
    if (_isLoaded)
        UnloadFont();
    _font = std::make_unique<::Font>(::LoadFont(fileName.c_str()));
    _isLoaded = true;
}

void Font::UnloadFont(void)
{
    if (_isLoaded) {
        ::UnloadFont(*(_font.get()));
        _isLoaded = false;
    }
}

}