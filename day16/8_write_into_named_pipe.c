#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
// named pipe:
//	stored as a file in the file system
//	has a name
//	requires no relationship between processes to communicate
// unnamed pipe:
//	there should be parent child or sibling relationship between the processes
//		to communicate
int main()
{
	int fd;
	char s[20];
	int n;
	fd = open("pipe", O_WRONLY); // read only or write only
	write(fd, "hello world", 11);
	close(fd);
	
}

// server - client
// squaring server :
//	client gives a number
//	server returns the square of it











