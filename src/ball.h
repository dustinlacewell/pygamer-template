#pragma once

#include "globals.h"
#include "audioPlayer.h"

// Ball class for a pong game.
// This is a simple class that has a position, velocity, and radius.

class Ball {
    public:
        float x;
        float y;

        float dx;
        float dy;

        float radius;
        float maxSpeed;

        Ball(float x, float y, float dx, float dy, float radius, float maxSpeed) {
            this->x = x;
            this->y = y;
            this->dx = dx;
            this->dy = dy;
            this->radius = radius;
            this->maxSpeed = maxSpeed;
        }

        void update(float dt) {
            x += dx * dt;
            y += dy * dt;

            if (x >= g_width - radius) {
                dx = -dx;
                x = g_width - radius;
                audio.play(KickSound);
            }

            if (x <= radius) {
                dx = -dx;
                x = radius;
                audio.play(KickSound);
            }

            if (y <= radius) {
                dy = -dy;
                y = radius;
                audio.play(KickSound);
            }

            if (y >= g_height - radius) {
                dy = -dy;
                y = g_height - radius;
                audio.play(KickSound);
            }
        }

        void draw() {
            g_canvas->fillCircle(x, y, radius, 0xFFFF);
        }
};

