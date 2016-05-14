#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

 // not working

// p and v operations
union semun
{
	unsigned short *array;
};
struct sembuf sb[2];
int main()
{
	int id;
	id = semget(0x1234, 3, 0666 | IPC_CREAT);
	if(id < 0)
	{
		perror("semget"); exit(1);
	}
	sb[0].sem_flg = SEM_UNDO;
	sb[1].sem_flg = SEM_UNDO;

	scanf("%d %d", &sb[0].sem_num, &sb[0].sem_op);
	scanf("%d %d", &sb[1].sem_num, &sb[1].sem_op);
	//semop(id, sb, 2);
	#if 1
	if(semop(id, sb, 2) < 0)
	{
		perror("semop"); exit(2);
	}
	#endif
	unsigned short a[3];
	union semun u; u.array = a;
	if(semctl(id, 0, GETALL, u) < 0)
	{
		perror("semctl"); exit(3);
	}
	for(int i = 0; i < 3; ++i)
	{
		printf("%d => %d\n", i, a[i]);
	}
}
