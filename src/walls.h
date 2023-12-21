#pragma once

#include "globals.h"

void drawWalls() {
        g_canvas->drawFastHLine(0, 0, g_width, 0xFFFF);
        g_canvas->drawFastHLine(0, g_height - 1, g_width, 0xFFFF);
        g_canvas->drawFastVLine(1, 1, g_height, 0xFFFF);   
        g_canvas->drawFastVLine(g_width - 1, 1, g_height, 0xFFFF);   
}