#ifdef _COMM_
#define _COMM_


#include<stdio.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<sys/msg.h>
#include<sys/type.h>

#define _PATH_ " "
#define _PROJ_ID_ 0x6666

int msg__create();
int msg_send();


#endif
