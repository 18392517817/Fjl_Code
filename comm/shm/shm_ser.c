#include"comm.h"

int main()
{
	//creat
	int shm_id=shm_creat();
	//attach
	
	char * addr=shm_attach(shm_id);
	while(1){
		printf("%s\n",addr);
		sleep(1);
	}
	//detach
	shm_detach(addr);
	//free
	shm_destroy(shm_id);
	return 0;
}
