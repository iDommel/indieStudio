/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** AudioDevice
*/

#ifndef AUDIODEVICE_HPP_
#define AUDIODEVICE_HPP_

#include <raylib.h>

namespace indie {
    class AudioDevice {
        public:
            ///  @brief Constructor a new audio device
            AudioDevice();
            ///  @brief Destruct the audio device:: close the audio device
            ~AudioDevice();
            ///  @brief Check if the audio device is playing
            bool Ready();
            ///  @brief Set the volume of the audio device
            void Volume(float volume);

        protected:
        private:
    };
}


#endif /* !AUDIODEVICE_HPP_ */
