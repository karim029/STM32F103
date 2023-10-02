# STM32F103 AFIO Driver

## Overview

The AFIO (Alternate Function I/O) driver for STM32F103 microcontrollers provides functions to configure EXTI (External Interrupt) pins and map them to specific ports. This allows you to set up and manage external interrupts for various peripherals and events in your STM32F103-based applications.

## Table of Contents

- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
  - [Setting EXTI Configuration](#setting-exti-configuration)
- [Contributing](#contributing)
- [License](#license)

## Getting Started

### Prerequisites

Before using this driver, make sure you have the following:

- STM32F103 microcontroller.
- STM32CubeIDE or a compatible development environment.
- Basic knowledge of STM32 microcontroller peripherals and GPIO pins.

### Installation

1. Clone or download this repository to your development environment.

2. Include the `AFIO_Interface.h` header file in your project.

3. Add the `AFIO_Program.c` source file to your project.

4. Configure the STM32CubeMX or your IDE to include the necessary paths for building your project.

5. Build and flash your project to the STM32F103 microcontroller.

## Usage

### Setting EXTI Configuration

You can use the `AFIO_setEXTI_config` function to configure EXTI lines and map them to specific ports. Here's how to use it:

```c
#include "AFIO_Interface.h"

int main() {
    // Configure EXTI Line 0 and map it to Port A
    AFIO_setEXTI_config(AFIO_EXTI0, AFIO_PORTA);
    
    // Your application code here
    
    return 0;
}
````
Make sure to include the necessary header files and call `AFIO_setEXTI_config()` with the appropriate EXTI line and port configurations in your application.

### Contributing
Contributions to this project are welcome. If you find any issues or have suggestions for improvements, please open an issue or create a pull request.

### License
This project is licensed under the MIT License - see the LICENSE file for details.