#ifndef __TASKS_CONFIG_H__
#define __TASKS_CONFIG_H__

#define tskcfgCONSOLE_TASK_NAME             "Console"
#define tskcfgCONSOLE_TASK_STACK_SIZE       256
#define tskcfgCONSOLE_TASK_PRIORITY         (tskIDLE_PRIORITY + 2)
#define tskcfgCONSOLE_TASK_PERIOD_TICKS     pdMS_TO_TICKS(2000)

#define tskcfgDISPLAY_TASK_NAME             "Display"
#define tskcfgDISPLAY_TASK_STACK_SIZE       256
#define tskcfgDISPLAY_TASK_PRIORITY         (tskIDLE_PRIORITY + 1)
#define tskcfgDISPLAY_TASK_PERIOD_TICKS     pdMS_TO_TICKS(1000)

#define tskcfgCAN_TASK_NAME                 "CanSniff"
#define tskcfgCAN_TASK_STACK_SIZE           256
#define tskcfgCAN_TASK_PRIORITY             (tskIDLE_PRIORITY + 3)
#define tskcfgCAN_TASK_PERIOD_TICKS         pdMS_TO_TICKS(250)
#define tskcfgCAN_TASK_QUEUE_LENGTH         10

#define tskcfgHTU21D_TASK_NAME              "HTU21D"
#define tskcfgHTU21D_TASK_STACK_SIZE        256
#define tskcfgHTU21D_TASK_PRIORITY          (tskIDLE_PRIORITY + 1)
#define tskcfgHTU21D_TASK_PERIOD_TICKS      pdMS_TO_TICKS(1000)

#define tskcfgMPL3115A2_TASK_NAME           "MPL3115A2"
#define tskcfgMPL3115A2_TASK_STACK_SIZE     256
#define tskcfgMPL3115A2_TASK_PERIOD_TICKS   pdMS_TO_TICKS(1000)
#define tskcfgMPL3115A2_TASK_PRIORITY       (tskIDLE_PRIORITY + 1)

#define tskcfgLIGHT_TASK_NAME               "Light"
#define tskcfgLIGHT_TASK_STACK_SIZE         256
#define tskcfgLIGHT_TASK_PRIORITY           (tskIDLE_PRIORITY + 1)
#define tskcfgLIGHT_TASK_PERIOD_TICKS       pdMS_TO_TICKS(1000)

#define tskcfgSTATUS_LED_TIMER_PERIOD_TICKS pdMS_TO_TICKS(500)

#endif // __TASKS_CONFIG_H__
