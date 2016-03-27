#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<signal.h>
static void usage()
{
	printf("Usage :./server [port]\n");
}
int start(int *ip,short int port)
{
	//socket();
	int sock_fd=socket(AF_INET,SOCK_STREAM,0);
	if(sock_fd==-1){
	perror("socket");
	return -1;
	}
	struct sockaddr_in local;
		local.sin_family=AF_INET;
		local.sin_port=htons(port);
		inet_aton(&ip,&local.sin_addr);
		//bind();绑定
	if(bind(sock_fd,(struct sockaddr *)&local,sizeof(local))==-1){
		perror("bind");
		return -1;
	}
	//listen();监听	
	if(listen(sock_fd,5)==-1){
		perror("listen");
		return -1;
	}
	return sock_fd;
}
void echo_data(int new_sock){
	while(1){
		char buf[1024];
		memset(buf,'\0',sizeof(buf));
		ssize_t sz=read(new_sock,buf,sizeof(buf)-1);
		if(sz>1){
			buf[sz]='\0';
			write(new_sock,buf,strlen(buf));
			printf("%s\n",buf);
		}else if(sz==0){
			printf("client is close\n");
			close(new_sock);
			break;
		}else{
			break;
		}
	}
}
static void *service(void *arg)
{
	printf("thread is create && detrach success\n");
	pthread_detach(pthread_self());
	int  new_sock=(int )arg;
	echo_data(new_sock);
}
int main(int argc,char* argv[])
{
	if(argc!=3){
		usage(argv[0]);
		return 1;
	}

	int port=atoi(argv[2]);//usefull sock
	int listen_sock=start(argv[1]/*ip*/,port/*port*/);
	if(listen_sock==-1){
		return 1;
	
	}
	//signal(SIGCHLD,recycle);
	signal(SIGCHLD,SIG_IGN);
	while(1){
		//setp 4
		struct sockaddr_in remote;
		memset(&remote,'\0',sizeof(remote));
		socklen_t len=sizeof(remote);
		//accept();阻塞，等待客户端连接
		int new_sock=accept(listen_sock,(struct sockaddr *)&remote,&len);
		if(new_sock<0){
			perror("accept");
		
		}else{
			printf("get a new client\n");
			pthread_t tid;
			int ret = pthread_create(&tid,NULL,service,(void *)new_sock);
			if(ret==0){
				
			}
	//		char buf[1024];
	//		memset(buf,'\0',strlen(buf));
	//		ssize_t sz=read(new_sock,buf,sizeof(buf)-1);
	//		if(sz>0){
	//			buf[sz]='\0';
	//			write(new_sock,buf,sizeof(buf)-1);
	//			printf("%s\n",buf);
	//		}else if(sz==0){
	//			printf("client is close\n");
	//			close(new_sock);
	//			break;
	//		}
	//		else{
	//			break;
	//		}
		}
	}
	
	return 0;
}
