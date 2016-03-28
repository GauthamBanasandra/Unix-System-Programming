#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;

	if( (fd = open("num.dat", O_RDONLY )) == -1)
	{
		perror("creat : "); exit(1);
	}
	printf("fd : %d\n", fd);
	int x; 
	if(read(fd, (void *)&x, sizeof(int)) != sizeof(int))
	{
		perror("read:");
	}
	if(close(fd) == -1)
	{
		perror("close : "); exit(1);
	}
	printf("x : %d\n", x);
	return 0;
}

