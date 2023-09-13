#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_fd[2]; // File descriptors for the pipe
    int child1, child2;

    // Create pipe
    if (pipe(pipe_fd) == -1) {
        perror("failed to create pipe");
        exit(1);
    }

    child1 = fork();

    if (child1 == -1) {
        perror("Child 1 fork failed");
        exit(1);
    }
/******* Child 1 ********/
    if (child1 == 0) {
        // Child 1 process
        close(pipe_fd[0]); // Close the read end of the pipe

        // Redirect stdout to the write end of the pipe
        dup2(pipe_fd[1], STDOUT_FILENO);

        // Close the original write end of the pipe
        close(pipe_fd[1]);

        // Now, Child 1's stdout is connected to the pipe
        printf("This is child 1s message, printed from child 2.");
        exit(0);
    }


/******** CHild 2 *********/
    child2 = fork();

    if (child2 == -1) {
        perror("fork");
        exit(1);
    }

    if (child2 == 0) {
        // Child 2 process
        close(pipe_fd[1]); // Close the write end of the pipe

        // Redirect stdin to the read end of the pipe
        dup2(pipe_fd[0], STDIN_FILENO);

        // Close the read end of the pipe
        close(pipe_fd[0]);

        //This'll store whats in the pipe
        char buffer[100]; 

        //This will get the data from the pipe.
        fgets(buffer, sizeof(buffer), stdin);

        //Print what was in the pipe.
        printf("%s", buffer);
        exit(0);
    }

    // Close both ends of the pipe in the parent process
    close(pipe_fd[0]);
    close(pipe_fd[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}

