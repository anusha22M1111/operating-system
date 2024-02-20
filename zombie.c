
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (child_pid == 0) {
        // This is the child process
        printf("Child process %d\n", getpid());
        exit(0); // Child process exits immediately
    } else {
        // This is the parent process
        printf("Parent process %d\n", getpid());
        sleep(10); // Sleep to let the child process become a zombie
        system("ps -o pid,ppid,stat,cmd"); // Display process status
    }

    return 0;
}

