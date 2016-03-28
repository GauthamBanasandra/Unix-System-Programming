#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>


#define KEY 0x1234
int main()
{
	int id;
	id = shmget(KEY, 1000, IPC_CREAT | 0666);
	if(id < 0)
	{
		perror("shmget:"); exit(1);
	}
	int *p = (int*)shmat(id, 0, 0);
	if(p == (int*)-1)
	{
		perror("shmat:"); exit(2);
	}
	int n = 20;
	for(int i = 0; i < n; ++i)
	{
		p[i] = i * i * i;
	}	
	sleep(1000);

	if(shmdt(p) == -1)
	{
		perror("shmdt:"); exit(3);
	}
	

}
