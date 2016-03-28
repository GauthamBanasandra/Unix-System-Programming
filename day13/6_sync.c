#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void handler_usr1(int signo)
{
	printf("child: recd signal number : %d\n", signo);
}
// 
int main()
{
	int pid;
	if(signal(SIGUSR1, handler_usr1) == SIG_ERR)
	{
		perror("Signal SIGUSER1 : "); exit(3);
	}

	pid = fork();
	if(pid < 0)
	{
		perror("fork"); exit(1);
	}
	else if(pid == 0) // child
	{
		printf("child waiting\n");
		pause();
		printf("child continues\n");
		
	}
	else // parent
	{
		//sleep(5);
		// parent send a signal to the child
		if(kill(pid, SIGUSR1) == -1)
		{
			perror("parent : kill  "); exit(2);
		}
	}
}
