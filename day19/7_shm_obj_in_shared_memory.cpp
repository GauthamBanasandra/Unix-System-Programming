#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <memory>
#include <iostream>
using namespace std;

class MyClass
{
	public:
	MyClass(int x) : x_(x) { cout << "ctor\n"; }
	~MyClass() { cout << "dtor\n"; }
	void disp() const
	{
		cout << "this is disp of MyClass\n";
	}
//	private:
	int x_;
};

#define KEY 0x1234
int main()
{
	int id;
	id = shmget(KEY, 1000, IPC_CREAT | 0666);
	if(id < 0)
	{
		perror("shmget:"); exit(1);
	}
	int *p = (int*)shmat(id, 0, 0);
	if(p == (int*)-1)
	{
		perror("shmat:"); exit(2);
	}
	MyClass *pc;
	pc = new (p) MyClass(111);
	printf("x : %d\n", pc->x_);
	if(shmdt(p) == -1)
	{
		perror("shmdt:"); exit(3);
	}
	MyClass *pc1 = (MyClass*)shmat(id, 0, 0);
	if(pc1 == (MyClass*)-1)
	{
		perror("shmat:"); exit(2);
	}
	pc1->disp();
	printf("x : %d\n", pc1->x_);


}
