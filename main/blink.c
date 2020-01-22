#include <stdio.h>
#include <string.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs_flash.h"
#include "sdkconfig.h"

#include "wifi/scan.c"
#include "wifi/access_point.c"
#include "decoders/rf433.c"

/* Can run 'make menuconfig' to choose the GPIO
*/
#define BLINK_GPIO CONFIG_BLINK_GPIO

void app_main()
{
    gpio_pad_select_gpio(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    // Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK( ret );

    // Switchin wifi mode
    if (false) {
        wifi_scan();
    } else {
        wifi_init_softap();
    }

    if (s_esp_RF433_queue == NULL) {
        s_esp_RF433_queue = xQueueCreate(1, sizeof(uint8_t));
        if (s_esp_RF433_queue != NULL) {
          // Configure the data input
          gpio_config_t data_pin_config = {
            .intr_type = GPIO_INTR_ANYEDGE,
            .mode = GPIO_MODE_INPUT,
            .pin_bit_mask = GPIO_SEL_22, // GPIO_NUM_22 (SEL) DATA PIN!
            .pull_up_en = GPIO_PULLUP_DISABLE,
            .pull_down_en = GPIO_PULLDOWN_DISABLE
          };

          gpio_config(&data_pin_config);

          // Attach the interrupt handler
          gpio_install_isr_service(ESP_INTR_FLAG_EDGE);
          gpio_isr_handler_add(GPIO_NUM_22, data_interrupt_handler, NULL);  // GPIO_NUM_22 DATA PIN!
          xTaskCreate(&receiver_rf433, "receiver_rf433", 2048, NULL, 3, NULL);
      }
    }

    while(1) {
        // Blink off (output low)
        printf("Turning off the LED\n");
        gpio_set_level(BLINK_GPIO, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        // Blink on (output high) */
        printf("Turning on the LED\n");
        gpio_set_level(BLINK_GPIO, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
