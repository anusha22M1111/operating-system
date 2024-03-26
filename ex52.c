

#include <stdio.h>

// Structure to represent a process
struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
};

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to implement the Round Robin scheduling algorithm
void roundRobinScheduling(struct Process processes[], int n, int time_quantum) {
    int remaining_processes = n;
    int current_time = 0;

    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                int execute_time = min(time_quantum, processes[i].remaining_time);
                current_time += execute_time;
                processes[i].remaining_time -= execute_time;

                if (processes[i].remaining_time == 0) {
                    remaining_processes--;
                    processes[i].completion_time = current_time;
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Initialize the processes with process_id, arrival_time, burst_time, and remaining_time based on user input
    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter details for process %d (arrival_time burst_time): ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].process_id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }
    int time_quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    // Perform Round Robin scheduling
    roundRobinScheduling(processes, n, time_quantum);

    // Calculate average waiting time and average turnaround time
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    printf("Process\t\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        int turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        int waiting_time = turnaround_time - processes[i].burst_time;
        total_waiting_time += waiting_time;
        total_turnaround_time += turnaround_time;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time, processes[i].completion_time, turnaround_time, waiting_time);
    }
    double average_waiting_time = (double)total_waiting_time / n;
    double average_turnaround_time = (double)total_turnaround_time / n;
    printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);

    // Display Gantt chart
    printf("\nGantt Chart:\n");
    printf("0");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < processes[i].completion_time; j++) {
            printf("--P%d--%d", processes[i].process_id, j + 1);
        }
    }
    printf("\n");

    return 0;
}

