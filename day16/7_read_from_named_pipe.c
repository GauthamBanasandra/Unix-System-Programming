#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int fd;
	char s[20];
	int n;
	fd = open("pipe", O_RDONLY); // read only or write only
	n = read(fd, s, 19);
	s[n] = '\0';
	printf("%s\n", s);
	close(fd);
	
}
