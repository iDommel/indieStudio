/*
** EPITECH PROJECT, 2022
** indie
** File description:
** animation
*/

#ifndef MODELANIMATIONH
    #define MODELANIMATIONH

    #include <iostream>

    struct ModelAnimation;
    struct Model;

    namespace indie {
        /**struct ModelAnimation;
         * @brief ModelAnimation object
         */ 
        class ModelAnimation {
            public:
                /**
                 * @brief Construct / load ModelAnimation object
                 * @param fileName Path to the animation file
                 * @param animsCount Pointer to the counter of the animation (default = 0)
                 */
                ModelAnimation(const char *fileName, unsigned int *animsCount);
                /**
                 * @brief Destroy ModelAnimation object
                 */
                ~ModelAnimation();

                /**
                 * @brief Update ModelAnimation object
                 * @param model Model to update
                 * @param frame Frame counter of the animation
                 */
                void updateModelAnimation(Model model, int frame);
                /**
                 * @brief Unload ModelAnimation object
                 */
                void unloadModelAnimation();
                /**
                 * @brief Check validity of ModelAnimation object
                 * @param model Model to check
                 */
                bool isValid(Model model);
                /**
                 * @brief Get the max frame of ModelAnimation object
                 */
                int getFrameCount();
            private:
                /**
                 * @brief List of animation object
                 */
                ::ModelAnimation *anims;
                /// @brief Boolean to see if the animation is loaded or not
                bool _isLoaded;
        };
    }

#endif /* !MODELANIMATIONH */
