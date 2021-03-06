#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>



#define KEY 0x1234
struct node
{
	int key;
	struct node* link;
};
typedef struct node node_t;
void disp(const node_t* p)
{
	while(p)
	{	
		printf("%d\n", p->key);
		p = p->link;
	}
	printf("\n");
}
int main()
{
	int id;
	id = shmget(KEY, 1000, IPC_CREAT | 0666);
	if(id < 0)
	{
		perror("shmget:"); exit(1);
	}
	node_t *head = (node_t*)shmat(id, 0, 0);
	if(head == (node_t*)-1)
	{
		perror("shmat:"); exit(2);
	}
	node_t *p = head;
	// could crash after displaying the first element
	disp(head);


	if(shmdt(head) == -1)
	{
		perror("shmdt:"); exit(3);
	}



}
