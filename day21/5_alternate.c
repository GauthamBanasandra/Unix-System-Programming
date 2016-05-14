#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define KEY1 0x2222
#define KEY2 0x3333

union semun
{
	int val;
};
struct sembuf p = { 0, -1, SEM_UNDO};
struct sembuf v = { 0, +1, SEM_UNDO};

int main()
{
	int id1 = semget(KEY1, 1, 0666 | IPC_CREAT);
	if(id1 < 0)
	{
		perror("semget"); exit(11);
	}
	int id2 = semget(KEY2, 1, 0666 | IPC_CREAT);
	if(id2 < 0)
	{
		perror("semget"); exit(11);
	}

	union semun u;
	u.val = 1;
	if(semctl(id1, 0, SETVAL, u) < 0)
	{
		perror("semctl"); exit(12);
	}
	u.val = 0;
	if(semctl(id2, 0, SETVAL, u) < 0)
	{
		perror("semctl"); exit(12);
	}
	int pid;
	pid =  fork();
	srand(pid);
	if(pid < 0)
	{
		perror("fork"); exit(1);
	}
	else if(pid)
	{
		char *s = "abcdefgh";
		int l = strlen(s);
		for(int i = 0; i < l; ++i)
		{
			if(semop(id1, &p, 1) < 0)
			{
				perror("semop p"); exit(13);
			}
			putchar(s[i]);
			fflush(stdout);
			sleep(rand() % 2);
			putchar(s[i]);
			fflush(stdout);
			if(semop(id2, &v, 1) < 0)
			{
				perror("semop p"); exit(14);
			}

			sleep(rand() % 2);
		}
	}
	else
	{
		char *s = "ABCDEFGH";
		int l = strlen(s);
		for(int i = 0; i < l; ++i)
		{
			if(semop(id2, &p, 1) < 0)
			{
				perror("semop p"); exit(15);
			}
			putchar(s[i]);
			fflush(stdout);
			sleep(rand() % 2);
			putchar(s[i]);
			fflush(stdout);
			if(semop(id1, &v, 1) < 0)
			{
				perror("semop p"); exit(16);
			}

			sleep(rand() % 2);
		}
	}
}
