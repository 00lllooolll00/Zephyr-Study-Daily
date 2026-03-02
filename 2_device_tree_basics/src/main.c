#include <zephyr/kernel.h>

int main(void)
{
    while (1)
    {
        printk("hello zephyr\n");
        k_msleep(1000);
    }

    return 0;
}
