#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    // Child Process
    if (pid == 0) {
        printf("Child Process: Executing date command\n");
        execl("/bin/date", "date", NULL);
        perror("execl failed");
        exit(1);
    }
    // Parent Process
    else {
        wait(NULL);  // Wait for child to finish
        printf("Parent Process: Executing cal command\n");
        execl("/usr/bin/cal", "cal", NULL);
        perror("execl failed");
        exit(1);
    }

    return 0;
}