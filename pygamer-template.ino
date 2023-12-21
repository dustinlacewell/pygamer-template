#include <stdint.h>

#include "Adafruit_Arcada.h"

#include "src/globals.h"
#include "src/scene.h"
#include "src/buttons.h"

#include "sceneA.h"


int lastTime = 0;

void setup(void)
{
  Serial.begin(9600);

  delay(100);

  Serial.println("Hello!");

  if (!arcada.arcadaBegin())
  {
    Serial.print("Arcada failed to begin!");
    while (1)
      delay(10);
  }

  arcada.displayBegin();
  arcada.setBacklight(255);
  arcada.enableSpeaker(true);

  if (arcada.createFrameBuffer(g_width, g_height))
  {
    g_canvas = arcada.getCanvas();
  }

  switchTo(new SceneA());
}

unsigned int getDeltaTime() {
  int now = millis();
  int deltaTime = lastTime == 0 ? 0 : now - lastTime;
  lastTime = now;
  return deltaTime;
}

void loop()
{
  unsigned int deltaTime = getDeltaTime();

  buttons.update();

  g_canvas->fillScreen(0x0000);
  currentScene->loop(deltaTime);
  arcada.blitFrameBuffer(0, 0);  
}