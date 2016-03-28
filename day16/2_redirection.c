#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	struct stat s;
	int fdout;
	//fdout = open("newfile.c", O_CREAT | O_WRONLY | O_TRUNC,  0644);
	fdout = open("newfile.c", O_CREAT | O_WRONLY,  0644);
	if(fdout  == -1)
	{
		perror("open"); exit(1);
	}
	write(fdout, "test", 4);
	if(fstat(fdout, &s) == -1)
	{
		perror("stat"); exit(2);
	}
	printf("size : %ld\n", s.st_size);
	close(fdout);

}

// experiments:
// 1. putchar(EOF);   // what happens
// 2. create a file; open the file for writing (O_CREAT | O_WRONLY); write something; check







