#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <string.h> 
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    //File that will be opened.
    const char *file = "openMe.txt";

    //Variable that'll hold the file_descriptor.
    int file_descriptor; 

    //Open the file.
    file_descriptor = open(file, O_CREAT | O_RDWR | O_TRUNC, 0666);

    if (file_descriptor < 0) {
        // Fork Failed.
        perror("Failed to open file");
        exit(1);
    }

    //Holds return value from forked process.
    int rc = fork();

    if (rc < 0) {
        //fork failed 
        fprintf (stderr, "fork failed\n");
        close(file_descriptor);
        exit(1); 
    }

    else if (rc ==0) {
        //Child process
        const char *childMessage = "Child message\n";
        write(file_descriptor, childMessage, strlen(childMessage));
    }

    else {
        //Parent process
        const char *parentMessage = "Parent message\n";
        write(file_descriptor, parentMessage, strlen(parentMessage)); 
    }

    close(file_descriptor);
    return 0;
}

/*****************************************************
Question 2: 

******************************************************/