#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<pthread.h>


void* thread_function(void* arg){
	printf("\tThread is successfully created and is running.\n");
	printf("\tThread ID: %lu\n", pthread_self());
	printf("\tThread is exiting!\n");
	pthread_exit(NULL);
}
int main(){

	pid_t pid;
	pthread_t thread;
	printf("\tParent Process- PID: %d, PPID: %d\n", getpid(), getppid());

	pid = fork();

	if(pid<0){
		printf("\tFork failed!\n");
	}
	else if(pid==0){
		printf("\tChild Process- PID: %d\n", getpid());
	}
	else {
		printf("\tParent process will wait for child process.\n");
		wait(NULL);
		printf("\tParent process detected completion of child process.\n\n");
	
		pthread_create(&thread, NULL, thread_function, NULL);
	        pthread_join(thread, NULL);
		printf("\tMain process resumed after termination of the thread!\n\n");

		printf("\tParent process detected termination of all child processes and threads!");
		printf("\tParent process has been terminated!\n\n");

	}

		
	
return 0;
}
