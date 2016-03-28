#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "err.h"
void cust_handler(int);

int main()
{
	struct sigaction sact;
	sact.sa_handler=cust_handler;
	sigemptyset(&sact.sa_mask);
	
	sigaction(SIGINT, &sact, 0)==-1?err("sigaction"):0;

	while(1);
	return 0;
}

void cust_handler(int signo)
{
	printf("signo=%d\n", signo);
	exit(1);
}
