// thread and process
//	thread => thread of execution ; sequence of instructions being executed

// A process has at least one thread
// thread executes in the context of a process
// process : placeholder for threads

// what does a thread share with the process?
//		virtual address space is same for all threads
//		text segment
//		data segment
//		heap segment
//		pid and ppid ... same
//		fd entries : shared
//		signal disposition : shared
//		how does a process react on being signaled?
//			one of the threads 
//		can we signal between threads? yes

//		signal blocking : per thread
//		signal pending  : per thread
//		
//		stack is not shared; divided between threads
// Each thread can have its own data : thread local storage(TLS)

// threads : no hierarchy
//	any thread can wait for any other thread to complete
//	
//	if a threaded process calls fork, only that thread is replicated
//  to take care of resources, we may register functions to be called
//		before forking, in parent after forking, in child after forking

// synchronization:
//	mutex
//	conditional variable
//	semaphore

// thread cancellation
//		cleanup handlers => implemented as macro














