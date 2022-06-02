/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** AudioDevice
*/

#ifndef AUDIODEVICE_HPP_
#define AUDIODEVICE_HPP_

namespace indie {
    class AudioDevice {
        public:
            ///  @brief Constructor a new audio device
            AudioDevice();
            ///  @brief Destruct the audio device:: close the audio device
            ~AudioDevice();
            ///  @brief isReady:: Check if the audio device is playing
            bool isReady();
            ///  @brief Set music volume
            void setVolume(float volume);

        protected:
        private:
    };
}


#endif /* !AUDIODEVICE_HPP_ */
