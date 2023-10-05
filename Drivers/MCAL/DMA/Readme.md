
# DMA Driver for stm32f103

## Introduction

This is a DMA (Direct Memory Access) driver for microcontroller-based systems. DMA allows for efficient data transfers between memory and peripherals without CPU intervention, which can significantly enhance system performance.

## Features

- Configurable DMA channel settings.
- Support for different data transfer directions (Memory to Memory, Peripheral to Memory, Memory to Peripheral).
- Circular mode for continuous data transfers.
- Configurable data increment options for both memory and peripherals.
- Support for different data sizes (BYTE, HALF_WORD, WORD).
- Configurable channel priority levels.
- Interrupt support for DMA transfer completion, half-transfer, and transfer error.

## How to Use

### 1. Include the Necessary Files

Make sure to include the following files in your project:

- `DMA_Interface.h`: Contains the DMA driver's public interface with configuration options and function declarations.
- `DMA_Private.h`: Contains private definitions and structures for the DMA driver.
- `DMA_Program.c`: Implementation of the DMA driver functions.

### 2. Configuration

Define your DMA channel configurations using the `DMA_ChannelConfig_t` struct. Set the desired values for direction, circular mode, data increment options, data sizes, and channel priority. For example:

```c
DMA_ChannelConfig_t channelConfig;
channelConfig.direction = MEM_TO_MEM;
channelConfig.circular = DMA_DISABLE_CIRCULAR;
channelConfig.peripheralIncrement = PERIPHERAL_INCREMENT_ENABLE;
channelConfig.memoryIncrement = MEM_INCREMENT_ENABLE;
channelConfig.peripheralSize = WORD;
channelConfig.memorySize = WORD;
channelConfig.channelPriority = DMA_LOW;
```

### 3. Initialize DMA

Initialize the DMA by configuring the desired channel with the previously defined configuration:

```c
uint8_t channel = CHANNEL1; // Select the DMA channel you want to configure
DMA_SetChannelConfiguration(channel, &channelConfig);
```

### 4. Enable DMA

Enable the DMA channel:

```c
DMA_enable(channel);
```

### 5. Interrupt Configuration (Optional)

If you want to use DMA interrupts, configure them as needed:

```c
// Enable transfer complete interrupt
DMA_interruptConfig(channel, DMA_TCIE, ENABLE);

// Enable half-transfer interrupt
DMA_interruptConfig(channel, DMA_HTIE, ENABLE);

// Enable transfer error interrupt
DMA_interruptConfig(channel, DMA_TEIE, ENABLE);
```

### 6. Set Callback Functions (Optional)

If you want to associate callback functions with DMA channels for interrupt handling, use the `DMA_setCallBack` function:

```c
void MyTransferCompleteCallback() {
    // Your code here
}

// Associate the callback function with the channel
DMA_setCallBack(channel, MyTransferCompleteCallback);
```

### 7. Start Data Transfer

Initiate data transfer as needed based on your application logic.



## License

This DMA driver is provided under the [MIT license]. Please refer to the LICENSE file for more details.

