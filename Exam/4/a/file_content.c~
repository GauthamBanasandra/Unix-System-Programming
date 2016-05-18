#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../../utils/utils.h"
#define BUFF_SIZE 1024

void file_content(char *fname)
{
	int id;
	char buf[BUFF_SIZE];
	
	if((id=open(fname, O_RDONLY))==-1)
		error("unable to open the file");
	
	printf("file:%s\n", fname);
	while(read(id, buf, BUFF_SIZE))
		printf("%s", buf);
		
	if(close(id)==-1)
		error("unable to close the file");
	printf("\n\n");
}
