#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <asm/uaccess.h>
#include <asm/page.h>
#include <asm/pgtable.h>

MODULE_LICENSE("GPL");

#define DCRRAW_NAME "dcrraw"

static dev_t dcrraw_dev;
static struct cdev dcrraw_cdev;

unsigned long dcr_read(unsigned long dcrn);
void dcr_write(unsigned long dcrn, unsigned long value);

static ssize_t dcrraw_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
	unsigned long res;
	unsigned long dcrn;
	
	if(len != 4) return -EINVAL;
	if(*off % 4 != 0) return -EINVAL;
	if(*off >= 4*1024) return -EINVAL;

	dcrn = (unsigned long)(*off / 4);
	
	//printk(KERN_WARNING "dcrraw: read from dcrn 0x%08lX\n", dcrn);
	res = dcr_read(dcrn);

	res = copy_to_user(buf, &res, 4);
	if(res){
		//printk(KERN_WARNING "dcrraw: copy_to_user failed\n");
		return -EFAULT;
	}
	
	return 4;
}

static ssize_t dcrraw_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
	unsigned long dcrn;
	unsigned long value;
	unsigned long res; 

	if(len != 4) {
		printk(KERN_DEBUG "dcrraw_write: wrong len :%i\n", (int)len);
		return -EINVAL;
	}
	
	if(*off % 4 != 0) {
		printk(KERN_DEBUG "dcrraw_write: wrong offset: %lu\n", *off);
		return -EINVAL;
	}

	if(*off >= 4*1024) {
		printk(KERN_DEBUG "dcrraw_write: offset to large: %lu\n", *off);
		return -EINVAL;
	}

	dcrn = (unsigned long)(*off / 4);

	if ((res = copy_from_user(&value, buf, 4))){
		printk(KERN_DEBUG "dcrraw_write: copy from user failed\n");
		res = -EFAULT;
	}

	printk(KERN_DEBUG "dcrrraw: writing value 0x%08lX to dcrn 0x%08lX\n", value, dcrn);

	dcr_write(dcrn, value);

	return 4;
}


static struct file_operations dcrraw_fops = {
	.owner = THIS_MODULE,
	.read  = dcrraw_read,
	.write = dcrraw_write,
};


static void dcrraw_exit(void)
{
	if(dcrraw_cdev.owner){
		cdev_del(&dcrraw_cdev);
	}
	if(dcrraw_dev){
		unregister_chrdev_region(dcrraw_dev, 1);
	}
	printk(KERN_ALERT "dcrraw exit\n");
}

static int dcrraw_init(void)
{
	int res;

	res = alloc_chrdev_region(&dcrraw_dev, 0, 1, DCRRAW_NAME);

	if (res < 0) {
		printk(KERN_ERR "dcrraw: can't allocate device number\n");
		dcrraw_exit();
		return res;
	}

	cdev_init(&dcrraw_cdev, &dcrraw_fops);
	dcrraw_cdev.owner = THIS_MODULE;
	
	res = cdev_add(&dcrraw_cdev, dcrraw_dev, 1);
	if(res < 0){
		printk(KERN_ERR "dcrraw: can't add char device\n");
		dcrraw_cdev.owner = NULL;
		dcrraw_exit();
		return res;
	}
	
	printk(KERN_ALERT "dcrraw init\n");

//	dcr_write(4,77);
//	dcr_write(4,5);

//	int sum = dcr_read(5);

//	printk(KERN_ALERT "dcr read @ dcrn 5 = %lu\n", sum);


	return 0;
}

module_init(dcrraw_init);
module_exit(dcrraw_exit);

