# RCC Driver for STM32F103

This is a README file for the RCC (Reset and Clock Control) driver for the STM32F103 microcontroller. The RCC driver provides functions to configure and control the clock system of the microcontroller.

## Table of Contents

- [Introduction](#introduction)
- [Directory Structure](#directory-structure)
- [Configuration](#configuration)
- [API Functions](#api-functions)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Reset and Clock Control (RCC) module is an essential part of the STM32F103 microcontroller, responsible for configuring and controlling the clock system. Proper configuration of the clock system is crucial for the operation of various peripherals and modules within the microcontroller.

This RCC driver provides a set of functions that allow users to configure and control the clock system according to their application's requirements.

## Directory Structure

The RCC driver directory includes the following files:

- `RCC_Config.h`: Configuration file where you can enable or disable different clock sources and set their parameters.
- `RCC_Interface.h`: Interface file containing function declarations for user interaction.
- `RCC_Private.h`: Private header file with internal definitions and bit masks.
- `RCC_Program.c`: Implementation of the RCC driver functions.

## Configuration

Before using the RCC driver, you should configure the `RCC_Config.h` file according to your application's requirements. In this file, you can enable or disable various clock sources and set their parameters, such as PLL source, PLL multiplication factor, AHB, APB1, and APB2 prescalers, and more.

## API Functions

The RCC driver provides the following API functions for users to configure and control the clock system:

### `void RCC_clearResetFlag()`

Clears the reset flags in the RCC_CSR register.

### `void RCC_resetModule(uint8_t peripheral_ID)`

Resets the specified hardware module identified by its peripheral ID. The peripheral ID should be selected from the available enums in `RCC_Interface.h`.

### `void RCC_enableClock(uint8_t peripheral_ID)`

Enables the clock for the specified peripheral module identified by its peripheral ID. The peripheral ID should be selected from the available enums in `RCC_Interface.h`.

### `void RCC_disableClock(uint8_t peripheral_ID)`

Disables the clock for the specified peripheral module identified by its peripheral ID. The peripheral ID should be selected from the available enums in `RCC_Interface.h`.

### `void RCC_Config()`

Initializes the system clock and other clock-related configurations based on the settings in `RCC_Config.h`. This function should be called to configure the clock system before starting your application.

## Usage

To use the RCC driver, follow these steps:

1. Configure the `RCC_Config.h` file according to your application's requirements.

2. Include the necessary headers in your application code:

   ```c
   #include "RCC_Config.h"
   #include "RCC_Interface.h"
   ```

3. Call the `RCC_Config()` function to initialize the clock system based on your configuration settings.

4. Use the provided API functions to enable or disable specific peripheral clocks and reset hardware modules when needed.

Example usage:

```c
int main() {
    // Initialize the clock system based on RCC_Config.h settings
    RCC_Config();

    // Enable the clock for a specific peripheral
    RCC_enableClock(RCC_USART1);

    // Reset a hardware module
    RCC_resetModule(RCC_GPIOA);

    // Application code here...

    return 0;
}
```

## Contributing

Contributions to this RCC driver are welcome. If you find issues, have suggestions for improvements, or want to add new features, please feel free to open an issue or submit a pull request on the [GitHub repository](https://github.com/your-repo-link).

## License

This RCC driver is provided under the [MIT License](LICENSE). You are free to use, modify, and distribute this software for any purpose, provided you include the original copyright notice and disclaimers.