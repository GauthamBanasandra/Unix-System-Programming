#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>


// p and v operations
union semun
{
	unsigned short *array;
};
int main()
{
	int id;
	id = semget(0x1234, 3, 0666 | IPC_CREAT);
	if(id < 0)
	{
		perror("semget"); exit(1);
	}
	unsigned short v[] = {3, 4, 5};
	union semun u;
	u.array = v;
	if(semctl(id, 0, SETALL, u) < 0)
	{
		perror("semctl"); exit(2);
	}
}
