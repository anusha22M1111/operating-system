#include <stdio.h>
#include <pthread.h>
int balance = 230000;
pthread_mutex_t lock;


void deposit(int amount) {
    pthread_mutex_lock(&lock);
    printf("account balance %d\n",balance);
    balance += amount;
    printf("Person X deposited %d\n", amount);
    printf("Current balance: %d\n", balance);
    pthread_mutex_unlock(&lock);
}


void withdraw(int amount) {
    pthread_mutex_lock(&lock);
    if (balance >= amount) {
        balance -= amount;
        printf("Person Y withdrew %d\n", amount);
        printf("Current balance: %d\n", balance);
    } else {
        printf("Insufficient balance for withdrawal.\n");
    }
    pthread_mutex_unlock(&lock);
}

void *personX(void *arg) {
    int depositAmount = 1000;
    deposit(depositAmount);
    return NULL;
}

void *personY(void *arg) {
    int withdrawAmount = 500;
    withdraw(withdrawAmount);
    return NULL;
}

int main() {
    pthread_t threadX, threadY;

    
    pthread_mutex_init(&lock, NULL);

 
    pthread_create(&threadX, NULL, personX, NULL);
    pthread_create(&threadY, NULL, personY, NULL);

   
    pthread_join(threadX, NULL);
    pthread_join(threadY, NULL);

    
    pthread_mutex_destroy(&lock);

    return 0;
}

