#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>


// 
int main()
{
	int pid;
	// ignore the sigchild signal explicitly
	if(signal(SIGCHLD, SIG_IGN) == SIG_ERR)
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
