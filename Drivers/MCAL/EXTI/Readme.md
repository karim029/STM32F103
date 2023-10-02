# STM32F103 EXTI Driver

## Overview

The EXTI (External Interrupt) driver for STM32F103 microcontrollers allows you to configure external interrupt lines and manage interrupt events. This driver provides functions to set up EXTI lines, enable/disable them, and trigger software interrupts. Additionally, it supports setting callback functions for EXTI lines to handle interrupt events in your STM32F103-based applications.

## Table of Contents

- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
  - [Initializing EXTI](#initializing-exti)
  - [Enabling and Disabling EXTI Lines](#enabling-and-disabling-exti-lines)
  - [Software Interrupt Trigger](#software-interrupt-trigger)
  - [Setting Callback Functions](#setting-callback-functions)
- [Contributing](#contributing)
- [License](#license)

## Getting Started

### Prerequisites

Before using this driver, ensure that you have the following:

- STM32F103 microcontroller.
- STM32CubeIDE or a compatible development environment.
- Basic knowledge of STM32 microcontroller peripherals and GPIO pins.

### Installation

1. Clone or download this repository to your development environment.

2. Include the `EXTI_Interface.h` header file in your project.

3. Add the `EXTI_Program.c` source file to your project.

4. Configure STM32CubeMX or your IDE to include the necessary paths for building your project.

5. Build and flash your project to the STM32F103 microcontroller.

## Usage

### Initializing EXTI

You can use the `EXTI_init` function to initialize EXTI lines with specific configurations. Example:

```c
#include "EXTI_Interface.h"

int main() {
    // Configure EXTI Line 0 to use Port A and trigger on a rising edge
    EXTI_init(EXTI_LINE0, AFIO_PORTA, RISING_EDGE);
    
    // Your application code here
    
    return 0;
}
````
## Enabling and Disabling EXTI Lines
Use the `EXTI_enableLine` and `EXTI_disableLine` functions to enable or disable EXTI lines, respectively. Example:
``````c
#include "EXTI_Interface.h"

int main() {
    // Enable EXTI Line 1
    EXTI_enableLine(EXTI_LINE1);
    
    // Disable EXTI Line 2
    EXTI_disableLine(EXTI_LINE2);
    
    // Your application code here
    
    return 0;
}
```````
## Software Interrupt Trigger
You can trigger EXTI interrupt lines using software with the EXTI_softWareTrigger function. Example:
`````C
#include "EXTI_Interface.h"

int main() {
    // Trigger EXTI Line 3
    EXTI_softWareTrigger(EXTI_LINE3);
    
    // Your application code here
    
    return 0;
}
``````
## Setting Callback Functions
To handle EXTI interrupt events, set callback functions using the set_CallBackFunction function. Example:

`````C
#include "EXTI_Interface.h"

// Callback function for EXTI Line 0
void EXTI0_Callback() {
    // Your code to handle EXTI Line 0 interrupt
}

int main() {
    // Set callback for EXTI Line 0
    set_CallBackFunction(EXTI_LINE0, EXTI0_Callback);
    
    // Your application code here
    
    return 0;
}
``````
## Contributing 
Contributions to this project are welcome. If you find any issues or have suggestions for improvements, please open an issue or create a pull request.

## License
This project is licensed under the MIT License - see the LICENSE file for details.
