#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../../utils/utils.h"

int main(int argc, char *argv[])
{
	if(argc==1)
	{
		printf("very few inputs\n");
		return 0;
	}

	if(argc>2)
	{
		printf("too many inputs\n");
		return 0;
	}
	
	DIR *dirp;
	struct dirent *dir;
	struct stat s;
	
	if((dirp=opendir(argv[1]))==NULL)
		error("unable to open dir");
	
	if(chdir(argv[1])==-1)
		error("unable to chdir");

	while(dir=readdir(dirp))
	{
		if(stat(dir->d_name, &s)==-1)
			error("unable to stat");
			
		if(s.st_size==0)
		{
			if(remove(dir->d_name)==-1)
				error("unable to delete file");
			printf("deleting %s\n", dir->d_name);
		}
	}
	
	return 0;
}
