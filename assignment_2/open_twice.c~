#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	if( (fd = open("a.dat", O_RDONLY)) == -1)
	{
		perror("open : "); exit(1);
	}
	printf("file opened\tfd=%d\n", fd);
	if( (fd = open("a.dat", O_RDONLY)) == -1)
	{
		perror("open : "); exit(1);
	}
	printf("file opened\tfd=%d\n", fd);
	while(1);
	if(close(fd) == -1)
	{
		perror("close : "); exit(1);
	}
	return 0;
}

