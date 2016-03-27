#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
static void usage()
{
	printf("./client [remote_ip][rem0te_port]\n");
}
int main(int argc,char *argv[])
{

	if(argc!=3){
		usage();
		return 1;
	}
//	short port=atoi(argv[2]);
//	//socket();
	int conn_fd=socket(AF_INET,SOCK_STREAM,0);
	if(conn_fd<0){
		perror("socket");
		return 1;
	
	}
	struct sockaddr_in remote;
	remote.sin_family=AF_INET;
	remote.sin_port=htons(8080/*port*/);
	remote.sin_addr.s_addr=inet_addr("192.168.20.137");
	printf("connet success...\n");
	char buf[1024];
	while(1){
		     struct sockaddr_in server;
			socklen_t len=sizeof(server);
			memset(buf,'\0',sizeof(buf));
			printf("please enter>");
			gets(buf);
			fflush(stdout);
			sendto(conn_fd,buf,sizeof(buf)-1,0,(struct sockaddr *)&remote,sizeof(remote));
			recvfrom(conn_fd,buf,sizeof(buf)-1,0,(struct sockaddr*)&server,&len);
			
			if(strncasecmp("quit",buf,4)){
				break;
			}
		 		
	}
	return 0;
}
