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
	short port=atoi(argv[2]);
	//socket();
	int conn_fd=socket(AF_INET,SOCK_STREAM,0);
	if(conn_fd<0){
		perror("socket");
		return -1;
	
	}
	struct sockaddr_in remote;
	remote.sin_family=AF_INET;
	remote.sin_port=htons(port);
	inet_aton(argv[1],&remote.sin_addr);
	//connet();建立连接
	if(connect(conn_fd,(struct sockaddr*)&remote,sizeof(remote))==-1){
		perror("connect");
		close(conn_fd);
		return 0;
	}
	printf("connet success...\n");
	char buf[1024];
	while(1){
		memset(buf,'\0',sizeof(buf));
		printf("please enter>");
		gets(buf);
		fflush(stdout);
		if(strncasecmp("quit",buf,4)){
			break;
		}
		
		write(conn_fd,buf,strlen(buf));
		int sz=read(conn_fd,buf,strlen(buf));
		if(sz>0){
			buf[sz]='\0';
			printf("echo data: %s\n",buf);
		}
	}
	return 0;
}
