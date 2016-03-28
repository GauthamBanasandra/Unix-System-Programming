


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
	int id;
	struct msqid_ds m;
	id = msgget(ftok("/home/kumar/pesit-2016", 'B'), IPC_CREAT | 0666);
	if(id < 0)
	{
		perror("msgget:"); exit(1);
	}
	if(msgctl(id, IPC_STAT, &m) < 0)
	{
		perror("msgctl:"); exit(2);
	}
	printf("uid : %d gid : %d mode : %o\n",
		m.msg_perm.uid,
		m.msg_perm.gid,
		m.msg_perm.mode);

	printf("msg queue created\n");
}
















