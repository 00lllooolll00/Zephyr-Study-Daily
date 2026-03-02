board_runner_args(esp32 "--esp-device=/dev/ttyUSB0")
board_runner_args(esp32 "--esp-baud-rate=2000000")
include(${ZEPHYR_BASE}/boards/common/esp32.board.cmake)

# 将默认烧录器设置为 esp32 (esptool)
board_set_flasher_ifnset(esp32)

board_runner_args(openocd "--config=board/esp32s3-builtin.cfg")
include(${ZEPHYR_BASE}/boards/common/openocd.board.cmake)

# 将默认调试器设置为 openocd
board_set_debugger_ifnset(openocd)
