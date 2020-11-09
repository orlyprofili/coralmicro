#include "third_party/freertos_kernel/include/FreeRTOS.h"
#include "third_party/freertos_kernel/include/task.h"
#include "third_party/nxp/rt1176-sdk/components/osa/fsl_os_abstraction.h"

#include <cstdio>

static void hello_task(void *param) {
    printf("Hello world FreeRTOS.\r\n");
    taskYIELD();
}

extern "C" void main_task(osa_task_param_t *arg) {
    int ret;
    ret = xTaskCreate(hello_task, "HelloTask", configMINIMAL_STACK_SIZE, NULL, configMAX_PRIORITIES - 1, NULL);
    if (ret != pdPASS) {
        printf("Failed to start HelloTask\r\n");
    }
    taskYIELD();
}