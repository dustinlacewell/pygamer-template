#pragma once

#define TEENSYDUINO 153

#include <Audio.h>

#include "globals.h"

#include "sounds/kick.h"

class SimpleAudioPlayer {
private:
    AudioPlayMemory player;
    AudioOutputAnalogStereo audioOut;
    AudioConnection patchCord;

public:
    SimpleAudioPlayer() : patchCord(player, 0, audioOut, 0) {
        AudioMemory(10);
    }

    void play(const unsigned int *sample) {
        if (player.isPlaying()) {
            player.stop();
        }

        player.play(sample);
    }

    void stop() {
        player.stop();
    }
};

SimpleAudioPlayer audio = SimpleAudioPlayer();