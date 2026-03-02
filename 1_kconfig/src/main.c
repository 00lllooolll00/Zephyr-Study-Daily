#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#ifdef CONFIG_USER_FUNC
#    include "user_func.h"
#endif

int main(void)
{
    while (1)
    {
        printk("hello zephyr!\n");
#ifdef CONFIG_USER_FUNC
        user_func();
#endif
        k_msleep(1000);
    }

    return 0;
}
