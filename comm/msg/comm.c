#include"comm.h"

static int msg_create_get(int flag)
{
	key_t _key=ftok(_PATH_,_PROJ_ID_);
	if(_key<0){
	perror("ftok");
	return -1;
	}
	int msg_id=msgget(_key,flag);
	if(msg_id<0){
		perror("msgget");
		return -2;
	}
	return msg_id;
}
int msg_create()
{
	//int flag=IPC_CREAT | IPC_EXCL;
	return msg_create_get(IPC_CREAT|IPC_EXCL|0777);
}
int msg_get()
{
	return msg_create_get(IPC_CREAT|0777);
}
int msg_send(int msg_id,char *msg,long mtype)
{
	msgbuf_t _buf;
	_buf.mtype=mtype;
	memset(_buf.mtext,'\0',sizeof(_buf.mtext));//
	int size=strlen(msg)>_G_SIZE_?_G_SIZE_-1:strlen(msg);
	strncpy(_buf.mtext,msg,size);
	return msgsnd(msg_id,&_buf,sizeof(_buf.mtext),0);
}

int msg_recv(int msg_id,char *out_msg,int out_len,long mtype)
{
	
	msgbuf_t msg_buf;
	
	memset(msg_buf.mtext,'\0',sizeof(msg_buf.mtext));

	int ret = msgrcv(msg_id,&msg_buf,sizeof(msg_buf.mtext),mtype,0);
	if(ret>=0){
		int size=strlen(msg_buf.mtext)>out_len?out_len-1:strlen(msg_buf.mtext);
		strncpy(out_msg,msg_buf.mtext,size);
		out_msg[size]='\0';
		return 0;
	}
	return 1;
}
int msg_destroy(int msg_id)
{
	int ret = msgctl(msg_id,IPC_RMID,NULL);
	if(ret==-1){
		perror("msgctl");
		return -3;
	}
	return ret;

}


