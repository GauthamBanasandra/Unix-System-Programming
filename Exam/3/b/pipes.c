#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include "../../utils/utils.h"

int main(int argc, char *argv[])
{
	int fd[2];
	int len;
	char *buf;
	pid_t pid;
	
	len=strlen(argv[1]);
	if(pipe(fd)==-1)
		error("unable to set up pipe");
	
	if(pid=fork())
	{
		if(write(fd[1], argv[1], len)!=len)
			error("unable to write to pipe");			

		wait(NULL);
		if(read(fd[0], buf, len)!=len)
			error("unable to read from the pipe");
		printf("from child=%s\n", buf);		
	}
	else
	{		
		sleep(2);
		if(read(fd[0], buf, len)!=len)
			error("unable to read from the pipe");
		
		buf[0]=buf[0]>=97 && buf[0]<=122?buf[0]-32:buf[0];
		
		if(write(fd[1], buf, len)!=len)
			error("unable to write to pipe");
	}
	
	return 0;
}
