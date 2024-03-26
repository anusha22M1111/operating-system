#include <stdio.h>

// Structure to hold the details of each person
struct Person {
    int id; // Person's ID
    int arrivalTime; // Arrival time of the person
    int serviceTime; // Time taken for the person to buy the ticket
    int waitingTime; // Waiting time for the person
    int turnAroundTime; // Turn around time for the person
};

// Function to calculate waiting time and turn around time for each person
void calculateTime(struct Person persons[], int n) {
    // First person's waiting time is 0
    persons[0].waitingTime = 0;

    // Calculating waiting time for each person
    for (int i = 1; i < n; i++) {
        persons[i].waitingTime = persons[i - 1].waitingTime + persons[i - 1].serviceTime - persons[i].arrivalTime;
        if (persons[i].waitingTime < 0) {
            persons[i].waitingTime = 0;
        }
    }

    // Calculating turn around time for each person
    for (int i = 0; i < n; i++) {
        persons[i].turnAroundTime = persons[i].serviceTime + persons[i].waitingTime;
    }
}

// FCFS Scheduling Algorithm
void FCFS(struct Person persons[], int n) {
    int totalWaitingTime = 0;
    int totalTurnAroundTime = 0;

    // Calculating waiting time and turn around time
    calculateTime(persons, n);

    // Calculating total waiting time and total turn around time
    for (int i = 0; i < n; i++) {
        totalWaitingTime += persons[i].waitingTime;
        totalTurnAroundTime += persons[i].turnAroundTime;
    }

    // Calculating average waiting time and average turn around time
    float avgWaitingTime = (float)totalWaitingTime / n;
    float avgTurnAroundTime = (float)totalTurnAroundTime / n;

    // Displaying average waiting time and average turn around time
    printf("Average Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turn Around Time: %.2f\n", avgTurnAroundTime);

    // Display Gantt Chart
    printf("Gantt Chart:\n");
    printf("--------------------------------------------------\n");
    printf("Person ID  Arrival Time  Service Time  Waiting Time  Turn Around Time\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-11d%-14d%-13d%-14d%d\n", persons[i].id, persons[i].arrivalTime, persons[i].serviceTime, persons[i].waitingTime, persons[i].turnAroundTime);
    }
    printf("--------------------------------------------------\n");
}

int main() {
    int n; // Number of persons in the queue
    printf("Enter the number of persons in the queue: ");
    scanf("%d", &n);

    // Input arrival time and service time for each person
    struct Person persons[n];
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for person %d: ", i+1);
        scanf("%d", &persons[i].arrivalTime);
        printf("Enter service time for person %d: ", i+1);
        scanf("%d", &persons[i].serviceTime);
        persons[i].id = i+1;
    }

    // Calculate average waiting time and average turn around time using FCFS
    FCFS(persons, n);

    return 0;
}
