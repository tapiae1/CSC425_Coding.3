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
        printf("hello\n");
    }

    else {
        //Parent process
        sleep(1);
        printf("goodbye\n");
    }

    return 0;
}   

/*
Question 1: I found that instead of the wait() function, you can add the sleep() function to allow the parent to not 
necessarily wait for the child to finish, but it will just allow the child process to run ahead of the parent. 


*/