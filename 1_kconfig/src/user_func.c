#include "user_func.h"
#include <zephyr/kernel.h>

void user_func(void)
{
    printk("Custom func\n");
}
