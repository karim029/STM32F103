# SysTick Driver for STM32F103

This is a simple SysTick driver for the STM32F103 microcontroller. It provides functions to configure and use the SysTick timer for timing operations.

## Functions

### `void SYSTICK_init()`

- Initializes the SysTick timer based on the user configuration in the `SYSTICK_Config.h` file.
- Sets the clock source to either AHB or AHB/8.
- Enables or disables interrupts.

### `void SYSTICK_reset()`

- Resets the registers and the load value of the SysTick timer.

### `uint32_t SYSTICK_getCurrentVal()`

- Retrieves the current value in the SysTick value register.

### `void SYSTICK_busyWait_MicroS(uint32_t microSeconds)`

- Delays for a specified number of microseconds using the busy wait method (no interrupts).
- Please note that the value should be in the range of 0x00000001-0x00FFFFFF (24 bits).

### `void SYSTICK_busyWait_MilliS(uint32_t milliSeconds)`

- Delays for a specified number of milliseconds using the busy wait method (no interrupts).
- Please note that the value should be in the range of 0x00000001-0x00FFFFFF (24 bits).

### `void SYSTICK_singleInterval(uint32_t microSeconds, callback fptr)`

- Delays for a specified number of microseconds using the interval wait delay method with interrupts.
- Executes a callback function once when the SysTick handler is executed.
- Works for a single interval only (1 time).

### `void SYSTICK_periodicInterval(uint32_t microSeconds, callback fptr)`

- Delays for a specified number of microseconds using the interval wait delay method with interrupts.
- Executes a callback function each time the SysTick timer underflows (periodic interval).
- You can disable SysTick to stop the function.

## Notes

- The following functions are not part of the user interface and should not be used directly:
  - `static void SYSTICK_start()`
  - `static void SYSTICK_stop()`
  - `void SysTick_Handler(void)`

## Configuration

- `SYSCLK_SOURCE` can be set to either `SYSCLK_AHB` or `SYSCLK_AHB_DIV_8`.
- `SYSTICK_INT_STATE` can be set to either `SYSTICK_INT_ENABLE` or `SYSTICK_INT_DISABLE`.

## Example Usage

Here is an example of how to use the SysTick driver:

```c
#include "SYSTICK_Interface.h"

void myCallback() {
    // Your code here
}

int main() {
    SYSTICK_init();
    // Use other functions to configure and use SysTick as needed

    // Example of using the periodic interval function with a callback
    SYSTICK_periodicInterval(1000000, myCallback);

    while (1) {
        // Your main code here
    }

    return 0;
}
```

In this example, we initialize the SysTick timer, configure it to generate periodic interrupts every 1 second (1,000,000 microseconds), and provide a callback function (`myCallback`) that will be executed when the SysTick interrupt occurs.

Please make sure to configure the driver according to your requirements in the `SYSTICK_Config.h` file before using it in your application.

## Author

- Author: Karim

Feel free to modify and adapt this driver to suit your specific STM32F103 microcontroller project needs.