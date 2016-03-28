
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void myhandler(int signo)
{
	printf("recd signal number : %d\n", signo);
	printf("SIGALRM recieved\n");
	exit(0);
}

int main()
{
	if(alarm(10) == -1)
	{
		perror("alarm"); exit(1);
	}
	printf("alarm set\n");
	// alarm cleared
	if(alarm(0) == -1)
	{
		perror("alarm"); exit(1);
	}
	printf("alarm set again\n");
	
	if(signal(SIGALRM, myhandler) == SIG_ERR)
	{
		perror("signal"); exit(1);
	}
	while(1)
	{
		printf("hello world\n");
	}

}














































