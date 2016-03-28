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
	printf("shared memory created or accessed\n");
}
