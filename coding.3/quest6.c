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
        // wait(NULL);
        printf("Hello, I'm the child process (pid:%d), and the parent is waiting.\n", (int) getpid());
    }

    else {
        //Parent process
        waitpid(rc, NULL, 0);
        printf("Hello, I'm the parent process (pid: %d), parent of %d.\n", getpid(), rc);
    }

    return 0;
}   
/*
waitpid() would be useful because, say you have multiple child processes running at the same time. And then you want the parent
to wait for a specific child, you would use waitpid() to wait for that process. 
Because of the different options in the waitpid() function, you can do different tasks while checking the child process. 
*/
