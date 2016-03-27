#include"comm.h"

int main()
{
	int msg_id =msg_get();
	if(msg_id<0){
		return 1;
	}
	char buf[_G_SIZE_];
	int ret =0;
	while(1){
		memset(buf,'\0',sizeof(buf));
		printf("Please Enter:");
		fflush(stdout);
		fgets(buf,sizeof(buf)-1,stdin);

		ret=msg_send(msg_id,buf,DATA_TYPE_CLI);
		if(strncasecmp("quit",buf,4)==0){
			break;
		}
		ret=msg_recv(msg_id,buf,sizeof(buf)-1,DATA_TYPE_SER);
		printf("ser:>%s\n",buf);
	}
	return 0;
}
