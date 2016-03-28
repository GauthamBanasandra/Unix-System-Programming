#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>

#define KEY 0x1234
int main()
{
	int id;
	struct shmid_ds s;
	id = shmget(KEY, 1000, IPC_CREAT | 0666);
	if(id < 0)
	{
		perror("shmget:"); exit(1);
	}
	if(shmctl(id, IPC_STAT, &s) < 0)
	{
		perror("shmctl:"); exit(2);
	}
	printf("attach time : %s\n", 
			ctime(&s.shm_atime));

	printf("detach time : %s\n", 
			ctime(&s.shm_dtime));

	printf("# of attach : %d\n", 
			s.shm_nattch);


}

