#include"sem_lock.h"
static int sem_creat_get(int nsems,int flags)
{
	key_t _key = ftok(_PATH_,_PROJ_ID_);
	if(_key<0)
	{
		perror("ftok");
		return -1;

	}
	return semget(_key,nsems,flags);
}
 int sem_creat(int nsems)
{
	return sem_creat_get(nsems,IPC_CREAT|IPC_EXCL|0777);
}
 int sem_get(int nsems)
{
	return sem_creat_get(nsems,IPC_CREAT);
}
int sem_init(int sem_id,int sem,int val)
{
	semum_t semval;
	semval.val=val;
	return semctl(sem_id,sem,SETVAL,semval);
}
static int my_sem_op(int sem_id,int sem,int op)
{
	struct sembuf _op;
	_op.sem_num=sem;
	_op.sem_op =op;
	_op.sem_flg=0;//SEM_UNDO
	return sem_op(sem_id, sem);
}
 int sem_p(int sem_id,int sem)
{
	return my_sem_op(sem_id,sem,-1);
}
 int sem_v(int sem_id,int sem)
{
	return my_sem_op(sem_id,sem,1);
}
int sem_destroy(int sem_id)
{

	return semctl(sem_id,0,IPC_RMID);
}
#ifdef _DEBUG_
int main()
{
	int nsems=1;
	int sem_id=sem_creat(nsems);
	sleep(3);
	sem_init(sem_id,0,1);
	sem_p(sem-id,0);
	sleep(1);
	sev_v(sem_id,0);
	sem_destroy(sem_id);
	return 0;
}
#endif
