#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	if( (fd = creat("a.dat", 0664)) == -1)
	{
		perror("creat : "); exit(1);
	}
	if(close(fd) == -1)
	{
		perror("close : "); exit(1);
	}
	return 0;
}

