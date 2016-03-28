#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALLOC(X) (X*)malloc(sizeof(X))
struct mystruct
{
	int size;
	char msg[1];
};

int main()
{
	struct mystruct *p;
	int n = 10;
	p = (struct mystruct *)malloc(sizeof(struct mystruct) + 
							      sizeof( (n-1) * sizeof(char)));
	p->size = 10;
	strcpy(p->msg, "pesit");

	printf("%d %s\n", p->size, p->msg);
	free(p);

}
