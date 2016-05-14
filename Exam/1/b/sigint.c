#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include "../../utils/utils.h"
void handler(int);
char* arg;

int main(int argc, char *argv[])
{
	arg=argv[1];	
	if(!strcmp("dfl", arg))	
	{
		if(signal(SIGINT, handler)==SIG_ERR)
			error("unable to register handler");
	}
	else if(!strcmp("ign", arg))	
	{
		if(signal(SIGINT, handler)==SIG_ERR)
			error("unable to register handler");
	}
	else
	{
		printf("format ./a.out [ign|dfl]\n");
		exit(1);
	}
		
	printf("waiting for the signal\npid=%d\tmode=%s\n", getpid(), arg);
	
	while(1);
	return 0;
}
