#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	if( (fd = creat("c.dat", 0664)) == -1)
	{
		perror("creat : "); exit(1);
	}
	lseek(fd, 100000, SEEK_SET);
	int x=12;
	write(fd, (void*)&x, sizeof(int));
	if(close(fd) == -1)
	{
		perror("close : "); exit(1);
	}
	return 0;
}

