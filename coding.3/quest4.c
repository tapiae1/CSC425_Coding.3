#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int rc = fork(); 

    if (rc == 0) { // Child process
        // Using execl()
        execl("/bin/ls", "ls", "-l", NULL);

        // Using execlp()
        execlp("ls", "ls", "-l", NULL);

        // Using execv()
        char *args[] = { "ls", "-l", NULL };
        execv("/bin/ls", args);

        // Using execvp()
        // char *args[] = { "ls", "-l", NULL };
        execvp("ls", args);

        perror("exec failed");
        exit(1);
    } else if (rc > 0) { 
        // Parent process
        wait(NULL); // Wait for the child to finish
        printf("Parent process is done.\n");
    } else { 
        // Fork failed
        perror("fork failed");
        return 1;
    }

    return 0;
}

/*
Question: The reason why there are so many different versions
is because they will be more useful depending on the situation that you are in.
I know that one of the exec() variants, you might not know the full path of where the program 
is going to be.
*/