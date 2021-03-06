#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void err(char *);
void alrm_handler(int);

int main()
{	
	signal(SIGALRM, alrm_handler);
	printf("waiting for alarm\tpid=%d\n", getpid());
	
	while(1);
	return 0;
}

void err(char *s)
{
	perror(s);
	exit(1);
}

// this handler will be called.
void alrm_handler(int signo)
{
	printf("interrupt handled in child\nsigno=%d\n", signo);
	exit(1);
}
