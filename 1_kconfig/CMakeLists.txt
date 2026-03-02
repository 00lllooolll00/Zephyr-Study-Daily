cmake_minimum_required(VERSION 3.20.0)

list(APPEND BOARD_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(1_kconfig)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

target_sources(app PRIVATE src/main.c)

# 只有 CONFIG_USER_FUNC 被定义了才会包含这个文件
target_sources_ifdef(CONFIG_USER_FUNC app PRIVATE
    src/user_func.c
)

target_compile_options(app PRIVATE
    -Wall
    -Wextra
    -g
)
