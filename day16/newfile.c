testlude <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void copy();
int main()
{
#if 0
	copy();
#endif
#if 0
	int fd;
	fd = open("1_redirection.c", O_RDONLY);
	if(fd  == -1)
	{
		perror("open"); exit(1);
	}
	close(0);
	dup(fd);
	close(fd);
	copy();
#endif
	int fd;
	int fdout;
	// fd will be 3
	fd = open("1_redirection.c", O_RDONLY);
	if(fd  == -1)
	{
		perror("open"); exit(1);
	}

	// fdout will be 4
	fdout = open("newfile.c", O_CREAT | O_WRONLY,  0644);
	if(fdout  == -1)
	{
		perror("open"); exit(1);
	}

	// close STDIN
	close(0);
	
	// now fd 0 is the same as 3
	dup(fd);
	// close fd 3
	close(fd);

	// close STDOUT
	close(1);
	// now fd 1 is the same as 4
	dup(fdout);
	// close fd 4
	close(fdout);

	// now, STDIN is 1_redirection.c and STDOUT is newfile.c
	copy();
}

void copy()
{
	char ch;
	while( (ch = getchar()) != EOF)
	{
		putchar(ch);
	}
}












