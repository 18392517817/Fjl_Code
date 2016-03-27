#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<signal.h>
static void usage(const char *msg)
{
	if(NULL!=msg){
		printf("%s[ip][port]\n",msg);
	}
}
//if succes return sock
//else return -1
int start(const char *const ip,short port)
{
	int sock=socket(AF_INET,SOCK_DGRAM,0);
	if(sock==-1){
		perror("socket");
		return -1;
	}
	struct sockaddr_in local;
	local.sin_family=AF_INET;
	local.sin_port=htons(port);
	local.sin_addr.s_addr=inet_addr(ip);
	if(bind(sock,(struct sockaddr*)&local,sizeof(local))==-1){
		perror("bind");
		return -1;
	}
	return sock;
}
int main(int argc,char*argv[])
{
	if(argc!=3){
		const char *msg="hello";
		usage(msg);
		return 1;
	}
	const char *ip =argv[1];
	short port=atoi(argv[2]);//ip转换成short
	int sock=start(ip,port);

			char *buf[1024];

	if(sock>0){
		while(1){
			struct sockaddr_in client;
			socklen_t len=sizeof(client);
			memset(buf,'\0',sizeof(buf));
			recvfrom(sock,buf,sizeof(buf)-1,0,(struct sockaddr *)&client,&len);
			printf("client  :%s\n",buf);
			sendto(sock,buf,sizeof(buf)-1,0,(struct sockaddr *)&client,&len);
		}
	}
	return 0;
}
