#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void myhandler(int signo)
{
	if(signal(SIGINT, SIG_IGN) == SIG_ERR)
	{
		perror("signal"); exit(1);
	}	
	
	// signo is the interrupt number listed in kill -l. For example, signo is 2 in this example, corresponding to SIGINT in kill -l
	printf("recd signal number : %d\n", signo);
	getchar();getchar();
	 
}

int main()
{
	if(signal(SIGINT, myhandler) == SIG_ERR)
	{
		perror("signal"); exit(1);
	}

	while(1)
	{
		printf("hello world\n");
	}
}
