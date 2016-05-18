#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../../utils/utils.h"
void handler(int);

int main()
{
	pid_t pid;
	register int i;
	register int j;
	
	if(pid=fork())
	{
		signal(SIGUSR1, handler);

		for(i=100; i>10; i-=20)
		{
			for(j=i; j>i-10; --j)
				printf("%d\t", j);		
			
			sleep(1);
			kill(pid, SIGUSR1);
			pause();
		}
		
		wait(NULL);
		printf("\n");
	}
	else
	{	
		signal(SIGUSR1, handler);
		for(i=90; i>0; i-=20)
		{
			pause();
			for(j=i; j>i-10; --j)
				printf("%d\t", j);
			
			sleep(1);
			kill(getppid(), SIGUSR1);
		}	
	}
	return 0;
}

void handler(int signo)
{
	printf("\n");
}
