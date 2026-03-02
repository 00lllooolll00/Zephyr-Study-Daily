cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(2_device_tree_basics)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

aux_source_directory(src APP_SRC)

target_sources(app PRIVATE ${APP_SRC})

target_compile_options(app PRIVATE
    -Wall
    -Wextra
)
