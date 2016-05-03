#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "err.h"

int main()
{
	int i, id;
	(id=shmget(12321, 1000, IPC_CREAT|0666))==-1?err("shmget"):0;
	int *p=(int*)shmat(id, 0, 0);
	(p==(int*)-1)?err("shmat"):0;

	printf("execed program\n");
	
	for(i=0; i<25; printf("%d\n", p[i++]));
	return 0;
}
