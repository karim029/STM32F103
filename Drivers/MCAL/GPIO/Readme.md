
# STM32F103 GPIO Driver

## Overview

The STM32F103 GPIO Driver is a library that provides functions to control and configure the General-Purpose Input/Output (GPIO) pins on STM32F103 microcontrollers. This driver simplifies GPIO operations such as setting pin directions, reading and writing pin values, and configuring pin modes.

## Table of Contents

- [Features](#features)
- [Prerequisites](#prerequisites)
- [Getting Started](#getting-started)
- [Functions](#functions)
- [Usage](#usage)
- [License](#license)

## Features

- Configurable GPIO pin modes: INPUT ANALOG, INPUT FLOATING, INPUT PULLUP, INPUT PULLDOWN, OUTPUT PUSH-PULL, OUTPUT OPEN DRAIN, OUTPUT ALTERNATE FUNCTION PUSH-PULL, OUTPUT ALTERNATE FUNCTION OPEN DRAIN.
- Functions to set pin directions for individual pins.
- Functions to set pin values (HIGH or LOW) for individual pins.
- Functions to read the value of individual pins.
- Functions to set port directions (LOW pins or HIGH pins) for an entire GPIO port.
- Functions to get the value of an entire GPIO port.

## Prerequisites

- STM32F103 microcontroller.
- STM32F103 GPIO peripheral knowledge.
- STM32F103 development environment (e.g., STM32CubeIDE, STM32CubeMX).
- Basic knowledge of embedded C programming.

## Getting Started

1. Include the necessary files in your STM32F103 project:
   - `types.h`
   - `bit_math.h`
   - `GPIO_Config.h`
   - `GPIO_Interface.h`
   - `GPIO_Program.c`

2. Configure your STM32F103 project to use the GPIO driver.

## Functions

The GPIO driver provides the following functions through the `GPIO_Interface.h` header file for user interaction:

- `GPIO_setPinDirection`: Set the direction (input or output) and mode of an individual GPIO pin.
- `GPIO_setPinValue`: Set the value (HIGH or LOW) of an individual GPIO pin.
- `GPIO_readPinValue`: Read the value (HIGH or LOW) of an individual GPIO pin.
- `GPIO_setPortDirection`: Set the direction (input or output) and mode of an entire GPIO port (LOW pins or HIGH pins).
- `GPIO_getPortValue`: Read the value of an entire GPIO port.

## Usage

Here's an example of how to use the GPIO driver in your STM32F103 project:

```c
#include "GPIO_Interface.h"

int main() {
    // Configure PIN0 of GPIOA as OUTPUT PUSH-PULL
    GPIO_setPinDirection(GPIOA, PIN0, GPIO_OUTPUT_10MHZ_PP);

    // Set PIN0 of GPIOA to HIGH
    GPIO_setPinValue(GPIOA, PIN0, HIGH);

    // Read the value of PIN0 of GPIOA
    uint8_t pinValue = GPIO_readPinValue(GPIOA, PIN0);

    // Set the direction of HIGH pins in GPIOB to INPUT FLOATING
    GPIO_setPortDirection(GPIOB, HIGH, GPIO_INPUT_FLOATING);

    // Read the value of the entire GPIOB port (HIGH pins)
    uint16_t portValue = GPIO_getPortValue(GPIOB, HIGH);

    while (1) {
        // Your application code here
    }

    return 0;
}
```

## License

This STM32F103 GPIO Driver is open-source software released under the [MIT License](LICENSE).
