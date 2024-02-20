#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3, pid4;

    pid1 = fork();
    if (pid1 == 0) 
    {
        sleep(3); 
        printf("Child 1 terminated. PID: %d\n", getpid());
        return 0;
    }

    pid2 = fork();
    if (pid2 == 0) 
    {
        sleep(2); 
        printf("Child 2 terminated. PID: %d\n", getpid());
        return 0;
    }

    pid3 = fork();
    if (pid3 == 0) 
    {
        sleep(1); 
        printf("Child 3 terminated. PID: %d\n", getpid());
        return 0;
    }

    pid4 = fork();
    if (pid4 == 0) 
    {
        sleep(4); 
        printf("Child 4 terminated. PID: %d\n", getpid());
        return 0;
    }

    for (int i = 0; i < 4; i++) 
        wait(NULL);

    printf("Parent process terminated. PID: %d\n", getpid());

    return 0;
}
