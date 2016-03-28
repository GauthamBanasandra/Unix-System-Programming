#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
void err(char *);
void alrm_handler(int);

int main()
{
	alarm(5)==-1?err("alarm"):0;
	signal(SIGALRM, alrm_handler);
	printf("alarm set\tpid=%d\n", getpid());
	
	execl("./execed", "execed", NULL)==-1?err("exec"):0;
	
	return 0;
}

void err(char *s)
{
	perror(s);
	exit(1);
}

// this handler won't be called everything is replaced by execed program.
void alrm_handler(int signo)
{
	printf("interrupt handled in parent\nsigno=%d\n", signo);
	exit(1);
}
