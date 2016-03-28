#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
// experiment : can we interchange the read and the write end; NO
int main()
{
	int fd[2];
	int pid1;
	int pid2;
	if( pipe(fd) == -1)
	{
		perror("pipe"); exit(3);
	}
	if( (pid1 = fork()) == -1)
	{
		perror("fork1 : "); exit(1);
	}
	else if(pid1) // parent
	{
		if ((pid2 = fork()) == -1)
		{
			perror("fork2 : "); exit(2);
		}
		else if(pid2) // parent
		{
			close(fd[0]); close(fd[1]);
			wait((int*)0); wait((int*)0);
		}
		else // child 2
		{
			close(0); dup(fd[0]);
			close(fd[0]); close(fd[1]);
			execl("/usr/bin/wc", "wc", "-l", (void*)0);
		}
			
	}
	else // child 1
	{	
		close(1); dup(fd[1]);
		close(fd[0]); close(fd[1]);
		execl("/bin/ls", "ls", (void*)0);
	}
	
}
