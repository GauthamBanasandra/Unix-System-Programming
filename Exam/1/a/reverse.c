#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../../utils/utils.h"

int main(int argc, char *argv[])
{
	int pos, fd;	
	char buf;
	
	if((fd = open(argv[1], O_RDONLY)) == -1)
		error("can't open file");
	
	for(pos = lseek(fd, -1, SEEK_END); pos>=0; lseek(fd, --pos, SEEK_SET))
	{
		read(fd, &buf, sizeof(char));
		printf("%c", buf);
	}

	printf("\n");
	
	if(close(fd))
		error("can't close the file");
	
	return 0;
}
