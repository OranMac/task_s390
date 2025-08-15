#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>

MODULE_LICENSE("Dual BSD/GPL");

// Declare parameters
static char *name = "DEFAULT";
static int repeat = 1;
static unsigned int delay = 1;

module_param(delay, int, 0000);
module_param(name, charp, 0000);
module_param(repeat, int, 0000);

static int hello_init(void)
{
        delay = delay * 1000;
        for(int i = 0; i < repeat; i++){
                mdelay(delay);
                printk(KERN_ALERT "%s\n",name);
        }
        return 0;
}
static void hello_exit(void)
{
        printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
