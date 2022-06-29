// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <cstdio>

#include "libs/base/gpio.h"
#include "libs/base/led.h"
#include "third_party/freertos_kernel/include/FreeRTOS.h"
#include "third_party/freertos_kernel/include/task.h"

// Toggles the User LED in response to button presses

//! [gpio-callback] Doxygen snippet for gpio.h
bool user_led_on = false;

// Callback for user button
void OnButtonPressed() {
    user_led_on = !user_led_on;
    coral::micro::led::Set(coral::micro::led::LED::kUser, user_led_on);
}

extern "C" void app_main(void* param) {
    printf("Press the user button.\r\n");

    // Register callback for the user button
    coral::micro::gpio::RegisterIRQHandler(coral::micro::gpio::Gpio::kUserButton, OnButtonPressed);
    vTaskSuspend(nullptr);
}
//! [gpio-callback] End snippet