#include <Arduino_FreeRTOS.h>
#include <LiquidCrystal_I2C.h>
#include "carmate.h"
#include "tasks_config.h"
#include "utils.h"

void prvTaskDisplay(void *pvParameters);
void prvTaskStatusLog(void *pvParameters);

void vShellInit(void) {
  xTaskCreate(prvTaskDisplay, tskcfgDISPLAY_TASK_NAME,
              tskcfgDISPLAY_TASK_STACK_SIZE, NULL, tskcfgDISPLAY_TASK_PRIORITY,
              NULL);

  vPrintf_P(PSTR("Shell started\n"));
}

void prvTaskDisplay(void *pvParameters) {
  WeatherReading xCurrWeatherReading;
  // set the LCD address to 0x27 for a 16 chars and 2 line display
  LiquidCrystal_I2C lcd(0x27, 16, 2, LCD_5x8DOTS, vDelay, vDelayMicroseconds);

  xSemaphoreTake(xI2cLock, portMAX_DELAY);
  lcd.begin();
  lcd.backlight();
  xSemaphoreGive(xI2cLock);

  TickType_t xNextWakeTime = xTaskGetTickCount();

  for (;;) {
    xSemaphoreTake(xWeatherReadingLock, portMAX_DELAY);
    xCurrWeatherReading = xLastWeatherReading;
    xSemaphoreGive(xWeatherReadingLock);

    float fTempC = xCurrWeatherReading.fTemp1C + xCurrWeatherReading.fTemp2C;
    fTempC /= 2.0;

    xSemaphoreTake(xI2cLock, portMAX_DELAY);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd << fTempC << "C ";
    lcd << xCurrWeatherReading.fRh << "RH";
    xSemaphoreGive(xI2cLock);

    portYIELD();

    xSemaphoreTake(xI2cLock, portMAX_DELAY);
    lcd.setCursor(0, 1);
    lcd << xCurrWeatherReading.fAltitudeM << "M ";
    lcd << xCurrWeatherReading.fLight << "V";
    xSemaphoreGive(xI2cLock);

    vTaskDelayUntil(&xNextWakeTime, tskcfgDISPLAY_TASK_PERIOD_TICKS);
  }
}
