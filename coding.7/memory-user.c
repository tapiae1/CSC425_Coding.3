#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
   // Turn the first argument (a string) into an integer
    int bytes = atoi(argv[1]);

    //Print process ID
    pid_t pid = getpid();
    printf("Process ID: %d\n", (int) pid);

    //Allocating memory
    char *memory = (char *)malloc(bytes + 1);
    printf("Memory Allocated\n");
    //flush the output, so the above string prints.
    fflush(stdout); 

    //Touch every entry in a loop by writing to each byte in the list of bytes, loop
    //runs forever.

   //while (1) {
        for (long long i = 0; i < bytes; i++) {
            memory[i] = 0; 
       //}

    //free = null;
    }
    free(memory);
    return 0;
}

