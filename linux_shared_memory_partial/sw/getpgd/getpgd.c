#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <asm/uaccess.h>
#include <asm/page.h>
#include <asm/pgtable.h>

MODULE_LICENSE("Dual BSD/GPL");

#define GETPGD_NAME "getpgd"

static dev_t getpgd_dev;
static struct cdev getpgd_cdev;

static ssize_t getpgd_read(struct file *filp, char __user *buf, size_t len, loff_t *ignore)
{
	unsigned long res;
	unsigned long data = (unsigned long)current->mm->pgd;
	
	printk(KERN_WARNING "should be something else\n");
	//printk(KERN_WARNING "getpgd: context.id = %lu current->pid = %d\n mm->owner->pid", current->mm->context.id, current->pid, current->mm->owner->pid);

	if(len < 4) return -EINVAL;
	
	res = copy_to_user(buf, &data, 4);
	if(res){
		printk(KERN_WARNING "getpgd: copy_to_user failed\n");
		return -EFAULT;
	}
	
	return 4;
}

static int getpgd_open(struct inode *inode, struct file *filp)
{
#if 0
	unsigned long * kernel_pgd = (unsigned long*)init_mm.pgd;

	unsigned long vaddr = (unsigned long)current->mm->pgd;
	unsigned long pgd_index = vaddr >> 22;
	unsigned long pgd_entry;
	unsigned long * pt;
	unsigned long pt_index = (vaddr >> 12) & 0x03FF;
	unsigned long page_offset = vaddr & 0x0FFF;
	unsigned long huge_page_offset = vaddr & 0x003FFFFF;
	unsigned long pte;

	printk(KERN_WARNING "\nGETPGD: process pgd = 0x%08lX\n", vaddr);
	printk(KERN_WARNING "GETPGD: kernel  pgd = 0x%08lX\n",(unsigned long)kernel_pgd);
	printk(KERN_WARNING "GETPGD: pdg_index   = 0x%08lX\n", pgd_index);
	printk(KERN_WARNING "GETPGD: pt_index    = 0x%08lX\n", pt_index);
	printk(KERN_WARNING "GETPGD: page_offsrt = 0x%08lX\n", page_offset);
	printk(KERN_WARNING "GETPGD: huge page offset = 0x%08lX\n", huge_page_offset);

	pgd_entry  = kernel_pgd[pgd_index];

	printk(KERN_WARNING "GETPGD: kernel pgd entry for the process pgd = 0x%08lX\n", pgd_entry);

	if(!(pgd_entry & 0x400)){
		unsigned long paddr;

		printk(KERN_WARNING "GETPGD: huge table detected\n");
		paddr = (pgd_entry & 0xFFFFF000) + huge_page_offset;

		printk(KERN_WARNING "GETPGD: physical address = 0x%08lX\n", paddr);
		
	}
	else {
		pt = (unsigned long*)((pgd_entry & 0xFFFFF000) + 0xC0000000);

		printk(KERN_WARNING "GETPGD: pt = 0x%08lX\n", (unsigned long)pt);

		pte = pt[pt_index];

		printk(KERN_WARNING "GETPGD: pte = 0x%08lX\n", pte);
	}
#endif
	return 0;
}


static struct file_operations getpgd_fops = {
	.owner = THIS_MODULE,
	.read  = getpgd_read,
	.open  = getpgd_open
};


static void getpgd_exit(void)
{
	if(getpgd_cdev.owner){
		cdev_del(&getpgd_cdev);
	}
	if(getpgd_dev){
		unregister_chrdev_region(getpgd_dev, 1);
	}
	printk(KERN_ALERT "getpgd unloaded\n");
}

static int getpgd_init(void)
{
	int res;
	res = alloc_chrdev_region(&getpgd_dev, 0, 1, GETPGD_NAME);

	if (res < 0) {
		printk(KERN_ERR "getpgd: can't allocate device number\n");
		getpgd_exit();
		return res;
	}

	cdev_init(&getpgd_cdev, &getpgd_fops);
	getpgd_cdev.owner = THIS_MODULE;
	
	res = cdev_add(&getpgd_cdev, getpgd_dev, 1);
	if(res < 0){
		printk(KERN_ERR "getpgd: can't add char device\n");
		getpgd_cdev.owner = NULL;
		getpgd_exit();
		return res;
	}
	
	printk(KERN_ALERT "getpgd loaded\n");

	printk(KERN_ALERT "PAGE_SHIFT = %d\n", PAGE_SHIFT);
	printk(KERN_ALERT "PMD_SHIFT = %d\n", PMD_SHIFT);
	printk(KERN_ALERT "PUD_SHIFT = %d\n", PUD_SHIFT);
	printk(KERN_ALERT "PGDIR_SHIFT = %d\n", PGDIR_SHIFT);
	
	printk(KERN_ALERT "PAGE_MASK = %d\n", PAGE_MASK);
	printk(KERN_ALERT "PMD_MASK = 0x%08lX\n", PMD_MASK);
	printk(KERN_ALERT "PUD_MASK = 0x%08lX\n", PUD_MASK);
	printk(KERN_ALERT "PGDIR_MASK = 0x%08lX\n", PGDIR_MASK);


	return 0;
}

module_init(getpgd_init);
module_exit(getpgd_exit);

