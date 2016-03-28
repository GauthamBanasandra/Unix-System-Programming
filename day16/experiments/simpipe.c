#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "err.h"

int main()
{
	int fd[2];
	char a[5];
	int pid;
	
	pipe(fd)==-1?err("pipe"):0;
	
	if((pid=fork())!=0)
	{
		printf("writing \"test\"\n");
		write(fd[1], "test", 4)!=4?err("write"):0;
		wait((void*)0);
	}
	else
	{		
		read(fd[0], a, 4)==-1?err("read"):0;
		printf("read=%s\n", a);
	}
	
	return 0;
}
