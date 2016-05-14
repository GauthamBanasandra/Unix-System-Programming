#include <stdio.h>
#include <signal.h>
#include "../../utils/utils.h"
void handler(int);
char* arg;

int main()
{
	arg="dfl";
	struct sigaction sa;	
	sa.sa_handler=handler;

	if(sigaction(SIGINT, &sa, (void *)0)==-1)
		error("unable to set sigaction");
		
	printf("waiting for the signal\npid=%d\n", getpid());
	
	while(1);
	return 0;
}
