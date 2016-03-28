#include <stdio.h>
#if 1
static void foo()
{
	printf("what: %s\n", "I am foo\n");
}
#endif
#if 0
void bar()
{
}
#endif
void foo();
void bar();
int main()
{
	printf("main\n");
	foo();
	bar();
}
