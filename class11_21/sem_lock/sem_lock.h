#ifndef _SEM_LOCK_
#define _SEM_LOCK_


#include<stdio.h>
#include<sys/type.h>
#include<sys/ipc.h>
#include<sys/sem.h>

#define _PATH_ "."
#define _PROJ_ID_ 0x6666

typedef union _semun{
	int value;
	struct semid_ds *buf;
	unsigned short *array;
}semum_t;

int sem_init(int sem_id,int sem,int val);
int sem_creat(int nsems);
int sem_get(int nsems);
int sem_p(int sem_id,int sem);
int sem_v(int sem_id,int sem);
int sem_destory(int sem_id);

#endif

