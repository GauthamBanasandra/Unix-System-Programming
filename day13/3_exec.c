
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void myhandler(int signo)
{
	printf("recd signal number : %d\n", signo);
	printf("execed pgm : SIGALRM recieved\n");
	exit(0);
}

int main()
{
	printf("execed program\n");
	
	if(signal(SIGALRM, myhandler) == SIG_ERR)
	{
		perror("signal"); exit(1);
	}
	while(1)
	{
		printf("execed : hello world\n");
	}

}

