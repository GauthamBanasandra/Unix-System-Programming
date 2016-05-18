#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../../utils/utils.h"

int is_dir(char* fname)
{
	struct stat s;
	
	if(stat(fname, &s)==-1)
		error("unable to stat");
	
	if((s.st_mode & S_IFMT)==S_IFDIR)
		return 1;
	return 0;
}
