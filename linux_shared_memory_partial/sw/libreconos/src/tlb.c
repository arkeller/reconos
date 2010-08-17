#include "reconos.h"

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

static int dcrraw_fd = -1;


static int open_dcrraw()
{
	dcrraw_fd = open("/dev/dcr",O_RDWR);
	if(dcrraw_fd == -1){
		perror("open '/dev/dcr'\n");
	}
	return dcrraw_fd;
}

static unsigned int dcr_read(int dcrn)
{
	off_t off;
	ssize_t len;
	unsigned long value;
	
	off = lseek(dcrraw_fd, dcrn*4, SEEK_SET);
	if(off == (off_t)-1){
		perror("lseek\n");
		return -1;
	}

	len = read(dcrraw_fd, &value, 4);
	if(len == -1){
		perror("read /dev/dcr");
		return -1;
	}
	
	return (unsigned int)value;
}

static void dcr_write(int dcrn, unsigned int value)
{
	off_t off;
	ssize_t len;
	unsigned long v = value;
	fprintf(stderr, "dcrwrite called with dcrn = %i\n", dcrn);
		
	off = lseek(dcrraw_fd, dcrn*4, SEEK_SET);
	if(off == (off_t)-1){
		perror("lseek\n");
	}
	len = write(dcrraw_fd, &v, 4);
	if(len == -1){
		perror("write /dev/dcr");
	}
}

#define TLB_INVALIDATE 0x147A11DA

void tlb_invalidate(reconos_tlb_t * tlb)
{
	fprintf(stderr, "tlb_invalidate called\n");	
	dcr_write(tlb->invalidate_dcrn,TLB_INVALIDATE);
}

void tlb_setid(reconos_tlb_t * tlb, unsigned long id){
	fprintf(stderr, "tlb_setid called\n");
	dcr_write(tlb->id_dcrn, id);
}

void tlb_init(reconos_tlb_t * tlb)
{
        fprintf(stderr, "tlb_init called\n");

	if(dcrraw_fd = -1) open_dcrraw();
	tlb->page_faults = 0;
	tlb->invalidate_dcrn = 11;
	tlb->id_dcrn = 10;
	tlb->status1_dcrn = 5;
	tlb->status2_dcrn = 4;
	
	tlb_invalidate(tlb);
}

uint32 tlb_hits(const reconos_tlb_t * tlb)
{
	if(!tlb) return -1;
	return dcr_read(tlb->status1_dcrn);	
}

uint32 tlb_misses(const reconos_tlb_t * tlb)
{
	if(!tlb) return -1;
	return dcr_read(tlb->status2_dcrn);
}

uint32 tlb_page_faults(const reconos_tlb_t * tlb){
	if(!tlb) return -1;
	return tlb->page_faults;
}

