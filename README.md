[English](./README_EN.md) | 简体中文

# Zephyr RTOS ESP32-S3 学习项目

本项目是一个基于 Zephyr RTOS 的系统化学习项目，通过多个递进式模块深入学习 Zephyr 的核心概念和实践应用。

## 项目特点

- **渐进式学习**：从基础到高级，循序渐进掌握 Zephyr RTOS
- **实战导向**：每个模块都包含可运行的示例代码
- **官方标准**：采用 Zephyr 官方推荐的 Freestanding 工作区模式
- **工具现代化**：使用 just 命令运行工具简化构建流程

## 硬件平台

**开发板**：[正点原子 DNESP32S3 开发板](http://www.openedv.com/docs/boards/esp32/ATK-DNESP32S3.html)

**主要特性**：
- 芯片：ESP32-S3 双核 Xtensa LX7 处理器
- 主频：最高 240MHz
- 内存：512KB SRAM
- 无线：Wi-Fi 802.11 b/g/n + Bluetooth 5 (LE)
- 外设：丰富的 GPIO、SPI、I2C、UART 等接口

## 开发环境

### 工作区模式

本项目采用 [Freestanding 工作区模式](https://docs.zephyrproject.org/latest/develop/application/index.html)，**不包含** Zephyr 源码。Zephyr SDK 和源码需要单独安装在系统中。

**优势**：
- 项目目录更简洁
- 便于版本控制
- 可以使用系统全局的 Zephyr 安装
- 支持使用最新版本的 Zephyr

### 构建工具

项目使用 [just](https://github.com/casey/just) 命令运行工具，每个模块目录下都有 `justfile` 提供便捷的构建命令。

## 快速开始

### 环境准备

1. 安装 Zephyr SDK 和依赖（参考 [Zephyr 官方文档](https://docs.zephyrproject.org/latest/develop/getting_started/index.html)）
2. 安装 just 命令工具：
   ```bash
   # Ubuntu/Debian
   sudo apt install just

   # 或使用 cargo
   cargo install just
   ```

### 构建和烧录

进入任意模块目录，使用 just 命令：

```bash
cd 0_base

# 干净构建（使用官方板级配置）
just bop

# 常规构建
just b

# 烧录到设备
just f

# 构建并烧录
just r

# 打开配置菜单
just m

# 清理构建
just c
```

## 项目结构

```
.
├── 0_base/                   # 基础模块
├── 1_kconfig/                # Kconfig 配置系统
├── 2_device_tree_basics/     # 设备树基础
└── 3_device_tree_semantics/  # 设备树语义
```

### 模块说明

#### 0_base - 基础模块
**学习目标**：
- Zephyr 项目基本结构
- 最小化应用程序
- 自定义板级支持文件（Board Support Package）
- 基本的构建和烧录流程

**内容**：
- 包含自定义的 `opendev_esp32s3` 板级配置
- 简单的主循环示例
- CMakeLists.txt 和 prj.conf 配置

#### 1_kconfig - Kconfig 配置系统
**学习目标**：
- 理解 Kconfig 配置机制
- 创建自定义配置选项
- 在代码中使用配置宏
- 使用 menuconfig 进行配置

**内容**：
- 自定义 Kconfig 文件
- 条件编译示例
- 用户自定义函数模块

#### 2_device_tree_basics - 设备树基础
**学习目标**：
- 设备树（Device Tree）基本概念
- DTS 文件语法
- 设备树覆盖（Overlay）
- 在代码中访问设备树节点

**内容**：
- 自定义 DTS 文件
- 设备树节点定义
- 属性访问示例

#### 3_device_tree_semantics - 设备树语义
**学习目标**：
- 设备树高级特性
- 绑定（Bindings）机制
- 设备树宏的使用
- 复杂设备树结构

**内容**：
- 高级设备树配置
- 设备驱动与设备树的关联
- 实际外设配置示例

## 构建命令参考

| 命令 | 完整命令 | 说明 |
|------|---------|------|
| `just bop` | `west build -p always -b dnesp32s3b/esp32s3/procpu` | 干净构建（使用官方板级配置） |
| `just b` | `west build` | 常规增量构建 |
| `just f` | `west flash` | 烧录到设备 |
| `just r` | `west build && west flash` | 构建并烧录 |
| `just m` | `west build -t menuconfig` | 打开配置菜单 |
| `just c` | `ninja clean -C build` | 清理构建产物 |

## 学习路径

建议按照以下顺序学习：

1. **0_base**：熟悉 Zephyr 项目结构和基本工作流程
2. **1_kconfig**：掌握配置系统，学会自定义配置选项
3. **2_device_tree_basics**：理解设备树基础，学会定义硬件资源
4. **3_device_tree_semantics**：深入设备树高级特性，实现复杂配置

每个模块都可以独立构建和运行，建议在完全理解当前模块后再进入下一个。

## 学习资源

- **主要参考**：[Interrupt 博客](https://interrupt.memfault.com/)（Memfault 团队维护）
- **官方文档**：[Zephyr Project Documentation](https://docs.zephyrproject.org/)
- **开发板文档**：[正点原子 DNESP32S3 文档](http://www.openedv.com/docs/boards/esp32/ATK-DNESP32S3.html)
- **ESP32-S3 技术参考**：[ESP32-S3 Technical Reference Manual](https://www.espressif.com/sites/default/files/documentation/esp32-s3_technical_reference_manual_en.pdf)

## 许可证

本项目仅用于学习目的。

## 贡献

欢迎提交 Issue 和 Pull Request 来改进本学习项目。
