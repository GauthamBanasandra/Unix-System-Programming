#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include "err.h"

int main()
{
	int i, id, pid;
	(id=shmget(ftok("/home/kumar/pesit-2016/USP", 'A'), 1000, IPC_CREAT|0666))==-1?err("shmget"):0;
	int *p=(int*)shmat(id, 0, 0);
	(p==(int*)-1)?err("shmat"):0;
	
	if((pid=fork())!=0)
	{
		for(i=0; i<20; ++i)
			p[i]=i*i;			
		wait((void*)0);
	}
	else
	{
		sleep(5);
		for(i=0; i<20; printf("%d\n", p[i++]));
	}
	return 0;
}
