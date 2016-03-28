


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
	m.msg_perm.mode = 0600;
	if(msgctl(id, IPC_SET, &m) < 0)
	{
		perror("msgctl:"); exit(2);
	}

}
















