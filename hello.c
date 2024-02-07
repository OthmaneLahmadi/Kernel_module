#include <linux/init.h>
#include <linux/module.h>

#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");

int param=333;

module_param(param,int,S_IRUSR|S_IWUSR);

void display(void){
printk(KERN_ALERT " param = %d",param);
}

static int hello_init(void){
printk(KERN_ALERT "hello world");
display();
return 0;
}

static void hello_exit(void){
printk(KERN_ALERT "God by");
}

module_init(hello_init);
module_exit(hello_exit);
