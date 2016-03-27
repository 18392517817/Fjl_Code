//comm.h
#ifndef _COMM_MSG_
#define _COMM_MSG_
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>

#define _PATH_ "./"
#define _PROJ_ID_ 0x6666
#define _G_SIZE_ 128
#define DATA_TYPE_CLI 1
#define DATA_TYPE_SER 1

typedef struct{
	long mtype;
	char mtext[_G_SIZE_];
}msgbuf_t;


//////////////////////////////////////////
int msg_create();
int  msg_send(int msg_id,char *msg,long mtype);
int msg_recv(int msg_id,char *out_msg,int out_len,long mtype );
int  msg_destroy(int);
int msg_get();
#endif
