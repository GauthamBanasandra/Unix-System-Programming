#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "../../utils/utils.h"
int is_dir(char*);

void dir_content(char *dname)
{
	int files=0;
	int dirs=0;
	DIR *dirp;
	struct dirent *dir;
	
	if((dirp=opendir(dname))==NULL)
		error("unable to open directory");
	
	if(chdir(dname)==-1)
		error("unable to chdir");
		
	printf("dir:%s\n", dname);	
	while(dir=readdir(dirp))
		if(strcmp(".", dir->d_name)&&strcmp("..", dir->d_name))
		{			
			printf("%s\n", dir->d_name);
			is_dir(dir->d_name)?++dirs:++files;
		}
	
	if(chdir("..")==-1)
		error("unable to chdir");
	
	printf("files=%d\tdirs=%d\n\n", files, dirs);
}
