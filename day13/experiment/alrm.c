#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void err(char *);
void alrm_handler(int);

int main()
{
	alarm(5)==-1?err("alarm"):0;
	signal(SIGALRM, alrm_handler);
	printf("waiting for alarm\npid=%d\n", getpid());
	while(1);
	return 0;
}
void err(char *s)
{
	perror(s);
	exit(1);
}

void alrm_handler(int signo)
{
	printf("interrupt handled\nsigno=%d\n", signo);
	exit(1);
}
