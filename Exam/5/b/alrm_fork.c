#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "../../utils/utils.h"
void hdlr_alrm(int);

int main(int argc, char *argv[])
{
	pid_t pid;
	int time;
	
	if(argc!=3)
	{
		printf("format:time -[fork|exec]\n");
		return;
	}
	
	time=atoi(argv[1]);
	
	if(time<=0)
	{
		printf("time must be positive\n");
		return;
	}
	
	signal(SIGALRM, hdlr_alrm);
	alarm(time);
	printf("alarm in %d s\n", time);
	printf("parent pid=%d\n", getpid());
	
	if(!strcmp(argv[2], "-fork"))
	{
		if(pid=fork())			
			pause();
		else
		{
			printf("child pid=%d\n", getpid());
			pause();
		}
	}
	else if(!strcmp(argv[2], "-exec"))
	{
		if(execl("called", "", NULL)==-1)
			error("unable to exec");
	}
	else
		printf("format:time -[fork|exec]\n");
		
	return 0;
}
