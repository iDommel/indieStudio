/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <string>
#include <memory>

struct Music;

namespace indie {
    class Music {
        public:
            ///  @brief Constructor a new music:: load music from file
            Music(const std::string &fileName);
            ///  @brief Destruct the music:: unload music
            ~Music();

            enum class MusicState {
                PLAY,
                PAUSE,
                STOP
            };

            ///  @brief Start music
            void PlayMusic();
            ///  @brief Stop music
            void StopMusic();
            ///  @brief Pause music
            void PauseMusic();
            ///  @brief Resume playing paused music
            void ResumeMusic();
            ///  @brief Set volume for music (1.0 is max level)
            void MusicVolume(float volume);
            ///  @brief Updates buffers for music
            void UpdateMusic();
            ///  @brief Get music time length (in seconds)
            float MusicTimeLength();
            ///  @brief Get current music time played (in seconds)
            float MusicTimePlayed();

        protected:
        private:
            std::unique_ptr<::Music> _music;
            MusicState _state = MusicState::STOP;
    };
}

#endif /* !MUSIC_HPP_ */
