#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "err.h"

int main()
{
	int fd[2];
	char a[5];
	int pid;
	
	pipe(fd)==-1?err("pipe"):0;
	
	if((pid=fork())!=0)
	{
		printf("enter some text\n");
		scanf("%s", a);

		close(fd[0]);
		close(1);
		dup(fd[1]);
		close(0);
		close(fd[1]);

		write(1, a, strlen(a))!=strlen(a)?err("write"):0;
		wait((void*)0);
	}
	else
	{		
		close(fd[1]);
		close(0);
		dup(fd[0]);
		close(fd[0]);

		read(0, a, 5)==-1?err("read"):0;
		printf("read=%s\n", a);
	}
	
	return 0;
}
