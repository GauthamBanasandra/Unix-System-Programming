#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	if( (fd = open("b.dat", O_RDWR)) == -1)
	{
		perror("open : "); exit(1);
	}
//	lseek(fd, 10, SEEK_END);
	char c='a';
	/*if(write(fd, (void*)&c, sizeof(char))!=sizeof(char))
	{
		perror("write:"); exit(1);
	}*/
	while(read(fd, (void*)&c, sizeof(char)))
		printf("%c", c);
	printf("\n");
	if(close(fd) == -1)
	{
		perror("close : "); exit(1);
	}
	return 0;
}

