#include"comm.h"

int shm_creat_get(int flag)
{
	key_t _key=ftok(_PATH_,_PROJ_ID_);
	if(_key<0){
	perror("ftok");
	return -1;
	}
	return shmget(_key,_SIZE_,flag);
}
int shm_creat()
{
	return shm_creat_get(IPC_CREAT|IPC_EXCL|0666);//|0600
}
int shm_get()
{
	return shm_creat_get(IPC_CREAT);
}
char* shm_attach(int shmid)
{
	return (char*)shmat(shmid,NULL,0);
}
int shm_detach(const void *shmaddr)
{
	return shmdt(shmaddr);
}
int shm_destroy(int shmid)
{
	return shmctl(shmid, IPC_RMID, NULL);
}


