#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include "err.h"

int main()
{
	int i, id, pid;
	(id=shmget(12321, 1000, IPC_CREAT|0666))==-1?err("shmget"):0;
	int *p=(int*)shmat(id, 0, 0);
	(p==(int*)-1)?err("shmat"):0;
	
	for(i=0; i<25; ++i)
			p[i]=i*i;	
	execl("shm_exec", "x", NULL);			
	return 0;
}
