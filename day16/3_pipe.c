#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int fd[2];
	char a[6];
	if(pipe(fd) == -1)
	{
		perror("pipe"); exit(1);
	}
	printf("%d : %d\n", fd[0], fd[1]);
	//printf("writing to the pipe\n");
	//write(fd[1], "hello", 5);
	//printf("after write\n");

	printf("reading from the pipe\n");
	read(fd[0], a, 5); // blocks for ever
	printf("After read\n");

}
