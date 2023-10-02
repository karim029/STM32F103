


# NVIC Driver for STM32F103

This branch in repo contains a driver for the Nested Vectored Interrupt Controller (NVIC) for the STM32F103 microcontroller series. The NVIC is responsible for managing and controlling interrupts on the STM32F103 microcontroller.

## Introduction

The STM32F103 NVIC driver provides functions for enabling, disabling, setting priorities, and managing interrupts. It is designed to work with the STM32F103 microcontroller and provides a convenient way to configure and manage interrupts in your applications.

## Features

- Enable and disable interrupts.
- Set priorities for interrupts.
- Check the status of interrupts.
- Configure interrupt grouping and sub-priorities.

## Usage

To use the NVIC driver in your STM32F103 project, follow these steps:

1. Clone or download this repository to your project directory.

2. Include the necessary header files in your project.

   ```c
   #include "NVIC_Interface.h"
   ```

3. Use the provided functions in your code to configure and manage interrupts.

   ```c
   // Example: Enable an interrupt
   NVIC_enableIRQn(IRQn_Type interrupt);
   ```

   Replace `interrupt` with the appropriate interrupt from the `IRQn_Type` enum.

4. Customize the driver as needed for your application.




## Example

Here's a simple example of how to use the NVIC driver to enable and configure an interrupt:

```c
#include "NVIC_Interface.h"

int main() {
    // Enable the EXTI0 interrupt
    NVIC_enableIRQn(EXTI0_IRQn);

    // Set the priority for EXTI0 interrupt
    NVIC_setPriority(EXTI0_IRQn, NVIC_16GROUP_0SUB, 2, 0);

    // Your application code here

    return 0;
}
```

## License

This NVIC driver is provided under the MIT License. See the [LICENSE](LICENSE) file for details.

## Support and Contribution

If you encounter any issues or have suggestions for improvements, please [open an issue](https://github.com/karim029/STM32F103/issues).

Feel free to contribute to this project by creating pull requests.


------

**Author:** Karim Tarek

