//comm.h
#ifndef _COMM_SHM_
#define _COMM_SHM_
////共享内存
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdio.h>
//#include<sys/wait.h>
//#include<unistd.h>
#include<stdio.h>

#define _PATH_ "./"
#define _PROJ_ID_ 0x6666
#define _SIZE_ 4096

//////////////////////////////////////////
int shm_creat();
char* shm_attach(int shmid);
int shm_detach(const void *shmaddr );
int  shm_destroy(int shmid);
int shm_get();

#endif
