#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

// 先访问到 `chosen` 节点下的 `app-led` 节点
#define LED_NODE DT_CHOSEN(app_led)

// 再通过这个节点来获取对应的 gpio
static const struct gpio_dt_spec app_led = GPIO_DT_SPEC_GET(LED_NODE, gpios);

int main(void)
{
    int err = 0;

    // 使用 `gpio_is_readt_dt` 来检查设备是否正确获取
    if (!gpio_is_ready_dt(&app_led))
    {
        printk("app_led is not ready yet\n");
        return -EIO;
    }

    // 然后使用 `gpio_pin_configure_dt` 来初始化这个设备
    err = gpio_pin_configure_dt(&app_led, GPIO_OUTPUT_ACTIVE);
    if (err < 0)
    {
        printk("app_led failed to configutration,err:%d\n", err);
        return -EIO;
    }

    bool led_status = false;

    while (1)
    {
        // 只要是结尾带 `_dt` 的，都可以直接传入一个设备
        // zephyr 会自动提取对应的属性，当然也可以使用
        // 不带有这个后缀的 API，只是需要自己处理设备
        // 的一些属性(e.g.port、pin)
        // gpio_pin_toggle(app_led.port, app_led.pin);
        gpio_pin_toggle_dt(&app_led);
        k_msleep(500);
        led_status = !led_status;

        if (led_status == false) printk("led turn off\n");
        else printk("led turn on\n");
    }

    return 0;
}
