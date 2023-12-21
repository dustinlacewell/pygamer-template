#include "sceneB.h"
#include "sceneA.h"

#include "src/buttons.h"


void SceneB::setup(void)
{
    counter = 0;
}

void SceneB::loop(unsigned long dt)
{
    if (
        buttons.pressed(ARCADA_BUTTONMASK_A) ||
        buttons.pressed(ARCADA_BUTTONMASK_B) ||
        buttons.pressed(ARCADA_BUTTONMASK_START) ||
        buttons.pressed(ARCADA_BUTTONMASK_SELECT)
    ) {
        switchTo(new SceneA());
    }

    counter++;    

    // draw the current counter value to the screen
    g_canvas->setTextSize(2);
    g_canvas->setTextColor(0xFFFF);
    g_canvas->setCursor(0, 0);
    g_canvas->print(counter);
}