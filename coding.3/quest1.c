#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int rc = fork();
	if (rc < 0) {
	//fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if (rc == 0){
	// child (new process)
		printf("hello, I am a child \n");
	}
	else {
	//parent goes down this path (main)
	printf("hello, I am a parent\n");
	}

	int x = 100;
	printf("Variable x is: %d\n", x);
	x++;
	printf("Variable x is now: %d\n", x);
	return 0;

}
/*********************************
Eduardo Tapia:
Question 1:The value of x in the child process is 100 in both the child and parent.
When adding 1 to x, it only changes in the value in the process that added 1. So
if I added 1 in the parent process, it wouldn't change in the child process. 

 


***********************************/

