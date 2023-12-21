#include "sceneA.h"
#include "sceneB.h"
#include "src/buttons.h"

void SceneA::setup(void) {
    reset();
}

void SceneA::loop(unsigned long dt)
{
    if (
        buttons.pressed(ARCADA_BUTTONMASK_A) ||
        buttons.pressed(ARCADA_BUTTONMASK_B) ||
        buttons.pressed(ARCADA_BUTTONMASK_START) ||
        buttons.pressed(ARCADA_BUTTONMASK_SELECT)
    ) {
        switchTo(new SceneB());
    }

    ball.update(dt);
    ball.draw();
    drawWalls();
}