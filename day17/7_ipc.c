#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
	int id;
	id = msgget(ftok("/home/kumar/pesit-2016", 'B'), IPC_CREAT | 0666);
	if(id < 0)
	{
		perror("msgget:"); exit(1);
	}
	if(msgctl(id, IPC_RMID, (struct  msqid_ds*)0) < 0)
	{
		perror("msgctl:"); exit(2);
	}


}
















