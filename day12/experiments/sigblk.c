#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void err(char *);
void int_handler(int);

int main()
{
	sigset_t sigset;
	sigset_t oldset;
	sigset_t pendset;
	
	sigemptyset(&sigset);
	sigemptyset(&oldset);	
	sigemptyset(&pendset);
	
	sigaddset(&sigset, SIGINT);
	
	signal(SIGINT, int_handler)==SIG_ERR?err("signal"):0;
	printf("waiting for signal\npid=%d\n", getpid());
	
	sigprocmask(SIG_BLOCK, &sigset, &oldset)==-1?err("mask"):0;	
	sleep(10);
	sigpending(&pendset)==-1?err("pending"):0;
	sigismember(&pendset, SIGINT)? printf("SIGINT pending\n"):0;
	
	return 0;
}

void err(char *s)
{
	perror(s);
	exit(1);
}

void int_handler(int signo)
{
	printf("interrupt handled\nsigno=%d\n", signo);
	exit(1);
}
