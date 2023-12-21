#pragma once

#include "src/state.h"
#include "src/walls.h"
#include "src/scene.h"


class SceneA : public Scene {
public:
    void setup(void);
    void loop(unsigned long dt);
};

