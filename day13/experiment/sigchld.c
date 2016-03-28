#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
void err(char *);
void chld_handler(int);

int main()
{
	int pid;
	signal(SIGCHLD, chld_handler)==SIG_ERR?err("chld"):0;
	if((pid=fork())==0)
	{
		printf("child\n");
		sleep(2);
	}	
	else
		sleep(5);
}

void err(char *s)
{
	perror(s);
	exit(1);
}

// called when a child becomes zombie?
void chld_handler(int signo)
{
	printf("signo=%d\n", signo);
	wait((void*)0);
}
