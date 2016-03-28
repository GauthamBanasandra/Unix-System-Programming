#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int fd[2];
	int pid;
	if(pipe(fd) == -1)
	{
		perror("pipe"); exit(1);
	}
	if( (pid = fork()) == -1)
	{
		perror("fork"); exit(2);
	}
	// check for return of system calls for errors
	else if(pid) // parent
	{
		char b[6];
		scanf("%s", b);
		close(fd[0]); close(1); dup(fd[1]); close(fd[1]); write(1, b, 5);
	}
	else // child
	{
		int n;
		char a[6];
		close(fd[1]); close(0); dup(fd[0]); close(fd[0]); n = read(0, a, 5); a[n] = '\0';
		printf("read %s\n", a); 
	}

}
