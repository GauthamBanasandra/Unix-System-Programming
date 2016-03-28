// what are the different ways to communicate between 2 processes?

// - file
// - redirection
// - signal
// - pipe
// - named pipe
// - popen
// - System V IPC
//		message queue
//		shared memory
//		semaphore
// - socket (BSD)
// - TLI (AT & T)
// - RPC (remote procedure call)

// System V IPC(Interprocess communicatio mechanism)
// * create an IPC resource : ___get
//   no ___unget
// * no name ; identified by numbers (id or key)
// * are kernel data structures
//	 (file is not!!)
//		persistence until a reboot
// * flat structures; no hierarchy
// * might get removed when in use


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
// creaing IPC structure
//		___get()
//		message queue : msgget
// 1. specify the KEY
// 2. make the key using the path and a character
// can we share the id?
// do we require to call ___get if id is already available?

#define KEY 0x1111
int main()
{
	int id;
//	id = msgget(KEY, IPC_CREAT | 0600);
//	id = msgget(KEY, IPC_CREAT | IPC_EXCL |  0600);

	id = msgget(ftok("/home/kumar/pesit-2016", 'B'), IPC_CREAT | 0666);

	if(id < 0)
	{
		perror("msgget:"); exit(1);
	}
	printf("msg queue created\n");
}
















