obj-m += task_1.o
# obj-m += task_2.o
obj-m += task_3.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:        
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
