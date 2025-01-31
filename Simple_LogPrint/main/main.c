#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "arch/sys_arch.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "portmacro.h"
#include "esp_system.h"
#include "math.h"

#define TAG "DICE"

int dicerole(){
	int random = esp_random();
	int posNumber = abs(random);
	int diceNumber = posNumber%6;
	return diceNumber;
}

void app_main(void)
{
    while (true) {
		ESP_LOGD(TAG, "random number %d", dicerole());
		vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}