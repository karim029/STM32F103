# SimpleRTOS 

## Introduction

SimpleRTOS is a minimalistic real-time operating system designed for resource-constrained embedded systems. It provides a simple task scheduling mechanism, allowing you to create and manage multiple tasks with different priorities.

## Features

- Task creation and prioritization.
- Periodic task execution.
- Minimal memory overhead.

## Getting Started

### Prerequisites

Before using SimpleRTOS, make sure you have the following:

- A microcontroller or development board compatible with SimpleRTOS.
- A toolchain and development environment set up for your hardware.
- The SimpleRTOS source code files integrated into your project.

### Usage

1. Include the necessary header files in your project:

   ```c
   #include "OS_Interface.h"
   ```

2. Define the number of tasks and the tick time in the `OS_Config.h` file:

   ```c
   #define numTasks 3
   #define OS_TICKTIME 1000 // in microseconds
   ```

3. Create tasks using the `OS_createTask` function in your main code. For example:

   ```c
   OS_createTask(0, 1000, task1, 0);
   OS_createTask(1, 500, task2, 0);
   OS_createTask(2, 2000, task3, 0);
   ```

   - `taskPriority`: The priority of the task (0 for the highest priority).
   - `taskPeriodicity`: The time interval for the task to execute (in milliseconds).
   - `fptr`: A pointer to the task function.
   - `taskFirstDelay`: An initial delay before the task starts executing (in milliseconds).

4. Start the SimpleRTOS scheduler using the `OS_start` function:

   ```c
   OS_start();
   ```

5. Implement your task functions. For example:

   ```c
   void task1() {
       // Your task1 code here
   }

   void task2() {
       // Your task2 code here
   }

   void task3() {
       // Your task3 code here
   }
   ```

6. Build and run your project on your target hardware.

## Example

Here's an example of how to create and manage tasks using SimpleRTOS:

```c
#include "types.h"
#include "bit_math.h"
#include "SYSTICK_Interface.h"
#include "OS_Config.h"
#include "OS_Interface.h"
#include "OS_Private.h"

void task1() {
    // Your task1 code here
}

void task2() {
    // Your task2 code here
}

void task3() {
    // Your task3 code here
}

int main() {
    OS_createTask(0, 1000, task1, 0);
    OS_createTask(1, 500, task2, 0);
    OS_createTask(2, 2000, task3, 0);
    
    OS_start();
    
    while (1) {
        // Your main application code here
    }
    
    return 0;
}
```

## Notes

- The SimpleRTOS scheduler uses the SysTick timer to manage task scheduling.
- Tasks are executed in order of priority, with higher-priority tasks preempting lower-priority ones.
- Tasks with the same priority are executed in a round-robin fashion.

## License

This project is open-source and available under the MIT License. See the `LICENSE` file for details.