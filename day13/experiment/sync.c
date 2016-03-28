#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void err(char *);
void usr_handler(int);

int main()
{
	int pid;
	signal(SIGUSR1, usr_handler)==SIG_ERR?err("usr"):0;
	
	if((pid=fork())==0)
	{
		printf("child process pausing\n");
		// waits for a signal
		pause();
		printf("child process resuming\n");		
	}
	else
	{
		sleep(2);
		printf("parent signalling the child\n");
		// send a signal to child
		kill(pid, SIGUSR1)==-1?err("kill"):0;
	}
	
	return 0;
}

void usr_handler(int signo)
{
	printf("signo=%d\n", signo);
}

void err(char *s)
{
	perror(s);
	exit(1);
}
