#include <linux/init.h>
#include <linux/module.h>
#include <asm/ccwdev.h>
MODULE_LICENSE("Dual BSD/GPL");

static int goblin_init(void){
	// IO Enable

	return 0;
}

static void goblin_exit(void){
	printk(KERN_ALERT ("Goodbye, cruel world\n"));
}

module_init(goblin_init);
module_exit(goblin_exit);