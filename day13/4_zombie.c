#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void myhandler(int signo)
{
	printf("recd signal number : %d\n", signo);
	printf("execing SIGCHILD recieved\n");
	wait((void*)0);
	
}
// 
int main()
{
	int pid;
	if(signal(SIGCHLD, myhandler) == SIG_ERR)
	{
		perror("Signal"); exit(2);
	}
	pid = fork();
	if(pid < 0)
	{
		perror("fork"); exit(1);
	}
	else if(pid == 0) // child
	{
		printf("child exits");
		
	}
	else // parent
	{
		printf("parent executing\n");
		sleep(1000);
		printf("signaled\n");
		sleep(1000);
	}
}
