#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mqueue.h>
#include "reconos.h"

int main() {	
 // send message queue
	char *send_buf;
	char *recv_buf;

	size_t len = 4;
	unsigned int prio = 1;
	int n = 0;
	struct mq_attr	hw_sw_attr;
	struct mq_attr	sw_hw_attr;

	mqd_t mqd_hw_sw;
	mqd_t mqd_sw_hw;

 	hw_sw_attr.mq_flags   = 0;
	hw_sw_attr.mq_maxmsg  = 10;
	hw_sw_attr.mq_msgsize = len;
	hw_sw_attr.mq_curmsgs = 0;
 
	sw_hw_attr.mq_flags   = 0;
	sw_hw_attr.mq_maxmsg  = 10;
	sw_hw_attr.mq_msgsize = len;
	sw_hw_attr.mq_curmsgs = 0;
 
	if ((mqd_hw_sw = mq_open("/hw_sw", O_RDWR|O_CREAT, 777,  &hw_sw_attr)) < 0)
		perror("open hw_sw");
	if ((mqd_sw_hw = mq_open("/sw_hw", O_RDWR|O_CREAT, 777, &sw_hw_attr)) < 0)
		perror("open sw_hw");

	send_buf = malloc(1024);
	recv_buf = malloc(1024);
	memset(send_buf, 0, 1024);
	memset(recv_buf, 0, 1024);

	rthread_attr_t rcv_attr;
	rthread_attr_init(&rcv_attr);
        reconos_res_t res[2] = {{&mqd_sw_hw,PTHREAD_MQD_T }, 
                        {&mqd_hw_sw,PTHREAD_MQD_T }};

	rthread_attr_init(&rcv_attr);
        rthread_attr_setslotnum(&rcv_attr, 0); 
        rthread_attr_setresources(&rcv_attr, res, 2);
	rthread_t mythread;
        rthread_create( &mythread, &rcv_attr, NULL);


	if (mq_send(mqd_sw_hw, &send_buf, len, prio) < 0)
		perror("mq_send");
	fprintf(stderr, "--------------->message sent, ptr = %i\n", send_buf);
	if (mq_send(mqd_sw_hw, &recv_buf, len, prio) < 0)
                  perror("mq_send");
        fprintf(stderr, "--------------->message sent, ptr = %i\n", recv_buf);
	int msglen = 12;
	memcpy(send_buf, "hello world", msglen);
	if (mq_send(mqd_sw_hw, &msglen, len, prio) < 0)
                   perror("mq_send");
        fprintf(stderr, "--------------->message sent, ptr = %i\n", recv_buf);


	if ((n = mq_receive(mqd_hw_sw, &msglen, len, &prio)) < 0)
		perror("my_receive");
	fprintf(stderr, "--------------->message received \n");

	
	fprintf(stderr, "------------------> new message is %d bytes long \n", msglen);
	fprintf(stderr, "memory at location \"recv_buf\" %s\n", recv_buf);
	fprintf(stderr, "memory at location \"recv_buf + 16\" %s\n", recv_buf + 16);

	sleep(10);

	return 1;


}
