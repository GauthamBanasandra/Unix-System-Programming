#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void int_handler(int);

int main()
{
	signal(SIGINT, int_handler);
	printf("waiting for signal\npid=%d\n", getpid());
	while(1);
	return 0;
}

void int_handler(int signo)
{
	printf("interrupt handled\nsigno=%d\n", signo);
	exit(1);
}
