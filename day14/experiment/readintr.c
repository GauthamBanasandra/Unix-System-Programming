#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "err.h"
void alrm_handler(int);
char a[21]="xyz";

int main()
{
	signal(SIGALRM, alrm_handler)==SIG_ERR?err("alrm"):0;
	alarm(5);
	read(0, a, 20)==-1?err("read"):0;

	return 0;
}

void alrm_handler(int signo)
{
	printf("signo=%d\n", signo);
	putchar(a[0]);
}
