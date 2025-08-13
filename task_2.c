#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

MODULE_LICENSE("Dual BSD/GPL");

// Declare parameters
static int size = 1;
static unsigned int blocksize = 1;

module_param(size, int, 0000);
module_param(blocksize, int, 0000);

unsigned int major = 10;
char *name = "TEST";

static int driver_init(void)
{
	register_blkdev(major, name);
        return 0;
}
static void driver_exit(void)
{
	register_blkdev(major, name);
        printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(driver_init);

int block_read( int fildes,
                long block,
                unsigned nblock,
                void *buf );
                
module_exit(driver_exit);
