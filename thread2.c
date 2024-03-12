#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *checkOddEven(void *num) {
    int number = *((int *)num);
    if (number % 2 == 0) {
        printf("Thread ID: %ld - Number %d is even\n", pthread_self(), number);
    } else {
        printf("Thread ID: %ld - Number %d is odd\n", pthread_self(), number);
    }
    pthread_exit(NULL);
}

//program 2
void *checkPrime(void *num) {
    int number = *((int *)num);
    int isPrime = 1;
    if (number <= 1) {
        isPrime = 0;
    } else {
        for (int i = 2; i <= number / 2; i++) {
            if (number % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }
    if (isPrime) {
        printf("Thread ID: %ld - Number %d is a prime number\n", pthread_self(), number);
    } else {
        printf("Thread ID: %ld - Number %d is not a prime number\n", pthread_self(), number);
    }
    pthread_exit(NULL);
}

int main() {
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);

    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, checkOddEven, (void *)&input);
    pthread_create(&tid2, NULL, checkPrime, (void *)&input);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}

output:
Enter a number: 23
Thread ID: 140310217156160 - Number 23 is odd
Thread ID: 140310208763456 - Number 23 is a prime number
