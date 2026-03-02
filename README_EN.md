English | [简体中文](./README.md)

# Zephyr RTOS ESP32-S3 Learning Project

This is a systematic learning project based on Zephyr RTOS, designed to help you master Zephyr's core concepts and practical applications through progressive modules.

## Project Features

- **Progressive Learning**: From basics to advanced topics, step by step mastery of Zephyr RTOS
- **Practice-Oriented**: Each module contains runnable example code
- **Official Standards**: Uses Zephyr's officially recommended Freestanding workspace mode
- **Modern Tooling**: Simplified build process using the just command runner

## Hardware Platform

**Development Board**: [Alientek DNESP32S3 Development Board](http://www.openedv.com/docs/boards/esp32/ATK-DNESP32S3.html)

**Key Features**:
- Chip: ESP32-S3 dual-core Xtensa LX7 processor
- Clock Speed: Up to 240MHz
- Memory: 512KB SRAM
- Wireless: Wi-Fi 802.11 b/g/n + Bluetooth 5 (LE)
- Peripherals: Rich GPIO, SPI, I2C, UART, and other interfaces

## Development Environment

### Workspace Mode

This project uses the [Freestanding workspace mode](https://docs.zephyrproject.org/latest/develop/application/index.html), which **does not include** Zephyr source code. The Zephyr SDK and source code need to be installed separately on your system.

**Advantages**:
- Cleaner project directory
- Better for version control
- Can use system-wide Zephyr installation
- Supports using the latest version of Zephyr

### Build Tools

The project uses the [just](https://github.com/casey/just) command runner. Each module directory contains a `justfile` that provides convenient build commands.

## Quick Start

### Environment Setup

1. Install Zephyr SDK and dependencies (refer to [Zephyr Official Documentation](https://docs.zephyrproject.org/latest/develop/getting_started/index.html))
2. Install the just command runner:
   ```bash
   # Ubuntu/Debian
   sudo apt install just

   # Or use cargo
   cargo install just
   ```

### Build and Flash

Navigate to any module directory and use just commands:

```bash
cd 0_base

# Clean build (using official board configuration)
just bop

# Regular build
just b

# Flash to device
just f

# Build and flash
just r

# Open configuration menu
just m

# Clean build artifacts
just c
```

## Project Structure

```
.
├── 0_base/                   # Base module
├── 1_kconfig/                # Kconfig configuration system
├── 2_device_tree_basics/     # Device tree basics
└── 3_device_tree_semantics/  # Device tree semantics
```

### Module Descriptions

#### 0_base - Base Module
**Learning Objectives**:
- Basic Zephyr project structure
- Minimal application
- Custom Board Support Package (BSP)
- Basic build and flash workflow

**Contents**:
- Custom `opendev_esp32s3` board configuration
- Simple main loop example
- CMakeLists.txt and prj.conf configuration

#### 1_kconfig - Kconfig Configuration System
**Learning Objectives**:
- Understanding Kconfig configuration mechanism
- Creating custom configuration options
- Using configuration macros in code
- Using menuconfig for configuration

**Contents**:
- Custom Kconfig file
- Conditional compilation examples
- User-defined function module

#### 2_device_tree_basics - Device Tree Basics
**Learning Objectives**:
- Basic Device Tree concepts
- DTS file syntax
- Device tree overlays
- Accessing device tree nodes in code

**Contents**:
- Custom DTS files
- Device tree node definitions
- Property access examples

#### 3_device_tree_semantics - Device Tree Semantics
**Learning Objectives**:
- Advanced device tree features
- Bindings mechanism
- Using device tree macros
- Complex device tree structures

**Contents**:
- Advanced device tree configuration
- Device driver and device tree association
- Real peripheral configuration examples

## Build Command Reference

| Command | Full Command | Description |
|---------|-------------|-------------|
| `just bop` | `west build -p always -b dnesp32s3b/esp32s3/procpu` | Clean build (using official board config) |
| `just b` | `west build` | Regular incremental build |
| `just f` | `west flash` | Flash to device |
| `just r` | `west build && west flash` | Build and flash |
| `just m` | `west build -t menuconfig` | Open configuration menu |
| `just c` | `ninja clean -C build` | Clean build artifacts |

## Learning Path

Recommended learning sequence:

1. **0_base**: Familiarize yourself with Zephyr project structure and basic workflow
2. **1_kconfig**: Master the configuration system and learn to create custom options
3. **2_device_tree_basics**: Understand device tree fundamentals and learn to define hardware resources
4. **3_device_tree_semantics**: Deep dive into advanced device tree features and implement complex configurations

Each module can be built and run independently. It's recommended to fully understand the current module before moving to the next one.

## Learning Resources

- **Primary Reference**: [Interrupt Blog](https://interrupt.memfault.com/) (maintained by Memfault team)
- **Official Documentation**: [Zephyr Project Documentation](https://docs.zephyrproject.org/)
- **Board Documentation**: [Alientek DNESP32S3 Documentation](http://www.openedv.com/docs/boards/esp32/ATK-DNESP32S3.html)
- **ESP32-S3 Technical Reference**: [ESP32-S3 Technical Reference Manual](https://www.espressif.com/sites/default/files/documentation/esp32-s3_technical_reference_manual_en.pdf)

## License

This project is for educational purposes only.

## Contributing

Issues and Pull Requests are welcome to improve this learning project.
