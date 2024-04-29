#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void createProcessTree() {
    pid_t p1, p2, p3, p4, p5, p6, p7, p8, p10, p11;
    
    // Process P1
    p1 = getpid();
    printf("P1 (PID: %d) -> ", p1);
    
    // Process P2
    p2 = fork();
    if (p2 == 0) {
        printf("P2 (PID: %d), ", getpid());
        printf("P2 (PPID: %d), ", getppid());
        // Process P5
        p5 = fork();
        if (p5 == 0) {
            printf("P5 (PID: %d), ", getpid());
            printf("P5 (PPID: %d), ", getppid());
            
            // Process P10
            p10 = fork();
            if (p10 == 0) {
                printf("P10 (PID: %d)\n", getpid());
                printf("P10 (PPID: %d), ", getppid());
                exit(0);
            }
            exit(0);
        }
        
        // Process P6
        p6 = fork();
        if (p6 == 0) {
            printf("P6 (PID: %d)\n", getpid());
            printf("P6 (PPID: %d), ", getppid());
           exit(0);
        }
        
        // Process P7
        p7 = fork();
        if (p7 == 0) {
            printf("P7 (PID: %d)\n", getpid());
            printf("P7 (PPID: %d), ", getppid());
            exit(0);
        }
        
        exit(0);
    }
    
    // Process P3
    p3 = fork();
    if (p3 == 0) {
        printf("P3 (PID: %d), ", getpid());
        printf("P3 (PPID: %d), ", getppid());
        // Process P4
        p4 = fork();
        if (p4 == 0) {
            printf("P4 (PID: %d), ", getpid());
            printf("P4 (PPID: %d), ", getppid());
            // Process P11
            p11 = fork();
            if (p11 == 0) {
                printf("P11 (PID: %d)\n", getpid());
                printf("P11 (PPID: %d), ", getppid());
                exit(0);
            }
            
            exit(0);
        }
        
        // Process P8
        p8 = fork();
        if (p8 == 0) {
            printf("P8 (PID: %d)\n", getpid());
            printf("P8 (PPID: %d), ", getppid());
            exit(0);
        }
        
        exit(0);
    }
}

int main() {
    createProcessTree();
    return 0;
}
