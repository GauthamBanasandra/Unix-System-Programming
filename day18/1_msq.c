#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main()
{
	int id;
	struct msqid_ds m;
	id =  msgget(ftok("/home/kumar/pesit-2016/USP", 'A'), IPC_CREAT | 0666);
	if(id < 0)
	{
		perror("msgget"); exit(1);
	}
	printf("id : %d\n", id);
	if(msgctl(id, IPC_STAT, &m) < 0)
	{
		perror("msgctl"); exit(2);
	}
	printf("# of msgs : %d\n", m.msg_qnum);
	printf("# of bytes : %d\n", m.msg_qbytes);
	printf("send time : %ld\n", m.msg_stime);
	printf("recv time : %ld\n", m.msg_rtime);
	printf("change time : %ld\n", m.msg_ctime);
	printf("send time : %s\n", ctime(&m.msg_stime));
	printf("recv time : %s\n", ctime(&m.msg_rtime));
	printf("change time : %s\n", ctime(&m.msg_ctime));

	
}
