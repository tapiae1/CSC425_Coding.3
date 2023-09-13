#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <string.h> 
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    //Holds return value from forked process.
    int rc = fork();
    
    if (rc < 0) {
        //fork failed 
        fprintf (stderr, "fork failed\n");
        exit(1); 
    }

    else if (rc ==0) {
        //Child process
        close(STDOUT_FILENO); //Closes standard output 
        // wait(NULL);
        printf("Hello, I'm the child process (pid:%d), and the parent is waiting.\n", (int) getpid());
    }

    else {
        //Parent process
        wait(NULL);
        printf("Hello, I'm the parent process (pid: %d), parent of %d.\n", getpid(), rc);
    }

    return 0;
}   
/*
When closing the descriptor, the child process won't be able to print out the message. 
*/
