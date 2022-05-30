/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Font
*/

#ifndef FONT_HPP_
#define FONT_HPP_

#include <memory>

struct Font;

namespace indie {
class Font {
    public:
        Font();
        Font(const std::string &fileName);
        ~Font();

        /**
         * @brief Get the default Font
         * @return the default Font
         */
        ::Font GetFontDefault(void) const;

        /**
         * @brief Load font from file into GPU memory (VRAM)
         * @param fileName Path to font file
         */
        void LoadFont(const std::string &fileName);

        /**
         * @brief Unload Font from GPU memory (VRAM)
         */
        void UnloadFont(void);

    protected:
    private:
        std::unique_ptr<::Font> _font;
        bool _isLoaded;
};
}

#endif /* !FONT_HPP_ */
