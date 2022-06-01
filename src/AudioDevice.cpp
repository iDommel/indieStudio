/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** AudioDevice
*/

#include <raylib.h>

#include "AudioDevice.hpp"
#include "exceptions/AudioDeviceError.hpp"

indie::AudioDevice::AudioDevice()
{
    InitAudioDevice();
    if (Ready() != true)
        throw AudioDeviceError("AudioDevice already initialized");
}

indie::AudioDevice::~AudioDevice()
{
    CloseAudioDevice();
}

bool indie::AudioDevice::Ready()
{
    return IsAudioDeviceReady();
}

void indie::AudioDevice::Volume(float volume)
{
    SetMasterVolume(volume);
}