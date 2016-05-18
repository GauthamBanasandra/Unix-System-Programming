#include <stdio.h>
int is_dir(char*);
void file_content(char *);
void dir_content(char *);

int main(int argc, char *argv[])
{
	register int i;
	
	if(argc==1)
		dir_content(".");
	else
		for(i=1; argv[i]; ++i)
			if(is_dir(argv[i]))
				dir_content(argv[i]);
			else
				file_content(argv[i]);
		
	return 0;
}
