#include <Arduino_FreeRTOS.h>
#include "carmate.h"

// the setup function runs once when you press reset or power the board
void setup() {
  vCoreInit();
  // vCanInit();
  vWeatherInit();
  vShellInit();

  xEventGroupSetBits(xSystemEvents, carmateSYSTEM_UP_EVT_BIT);

  // Now the task scheduler, which takes over control of scheduling individual
  // tasks, is automatically started.
}

void loop() {
  // Empty. Things are done in Tasks.
}
