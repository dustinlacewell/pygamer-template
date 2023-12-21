#pragma once

#include "src/state.h"
#include "src/scene.h"


class SceneB : public Scene {
private:
    int counter = 0;
public:
    void setup(void);
    void loop(unsigned long dt);
};
