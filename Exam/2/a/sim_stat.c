#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include "../../utils/utils.h"

int main(int argc, char *argv[])
{
	struct stat s;
	
	if(stat(argv[1], &s)==-1)
		error("unable to stat");
	
	printf("file type:\t");
	switch(s.st_mode & S_IFMT)
	{
		case S_IFREG:
			printf("regular file\n");
			break;
		case S_IFDIR:
			printf("directory\n");
			break;
		case S_IFLNK:
			printf("symbolic link\n");
			break;
		default:
			printf("unknown\n");
	}
	
	printf("permission:\t%lo\n", (unsigned long)s.st_mode);
	printf("inode num:\t%ld\n", (long)s.st_ino);
	printf("link count:\t%ld\n", (long)s.st_nlink);
	printf("file size:\t%lld B\n", (long long)s.st_size);
	
	printf("status changed:\t%s", ctime(&s.st_ctime));
	printf("last file access:\t%s", ctime(&s.st_atime));
	printf("file last modified:\t%s", ctime(&s.st_mtime));
	
	return 0;
}
