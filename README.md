# Zephyr RTOS ESP32-S3 学习项目

本项目是一个基于 Zephyr RTOS 的学习项目，通过多个模块逐步学习 Zephyr 的核心概念。

## 工作区模式

当前目录**不包含** Zephyr 源码，采用的是 Zephyr 官方所谓的 [Freestanding 工作区模式](https://docs.zephyrproject.org/latest/develop/application/index.html)。本项目使用 Zephyr 最新版本。

## 硬件平台

使用的开发板是 [正点原子 DNESP32S3 开发板](http://www.openedv.com/docs/boards/esp32/ATK-DNESP32S3.html)。

## 构建工具

项目使用 [just](https://github.com/casey/just) 命令运行工具。每个模块目录下都有 `justfile`，提供了便捷的构建命令别名，如：
- `just bop` - 干净构建（使用 Zephyr 对该开发版配置好的文件）
- `just b` - 常规构建
- `just f` - 烧录到设备
- `just r` - 构建并烧录

## 学习资源

整个学习过程参考了 [Interrupt](https://interrupt.memfault.com/) 博客（Memfault）。

## 项目结构

```
.
├── 0_base/                   # 基础模块
├── 1_kconfig/                # Kconfig 配置系统学习
├── 2_device_tree_basics/     # 设备树基础
└── 3_device_tree_semantics/  # 设备树高级概念
```
