#pragma once

#include "globals.h"
#include "ball.h"

Ball ball = Ball(g_width - g_width / 4, g_height / 2, .2, .1, 4, .25);

void reset() {
    ball = Ball(g_width - g_width / 4, g_height / 2, .2, .1, 4, .25);
}
