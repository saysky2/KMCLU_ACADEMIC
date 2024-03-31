// priority scheduling algorithm

#include <stdio.h>

struct Process {
    int pid;       // Process ID
    int priority;  // Priority
    int burst;     // Burst time
};

void priorityScheduling(struct Process proc[], int n) {
    int total_time = 0;
    int waiting_time = 0;

    printf("Process ID\tPriority\tBurst Time\tWaiting Time\n");

    // Find the process with the highest priority
    int highest_priority_index = 0;
    for (int i = 1; i < n; i++) {
        if (proc[i].priority < proc[highest_priority_index].priority) {
            highest_priority_index = i;
        }
    }

    // Print and update waiting time for the process with the highest priority
    printf("%d\t\t%d\t\t%d\t\t%d\n", proc[highest_priority_index].pid, proc[highest_priority_index].priority, proc[highest_priority_index].burst, waiting_time);
    total_time += waiting_time + proc[highest_priority_index].burst;
    waiting_time += proc[highest_priority_index].burst;

    // Print and update waiting time for the remaining processes
    for (int i = 0; i < n; i++) {
        if (i != highest_priority_index) {
            printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].priority, proc[i].burst, waiting_time);
            total_time += waiting_time + proc[i].burst;
            waiting_time += proc[i].burst;
        }
    }

    float avg_waiting_time = (float)waiting_time / n;
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Total Turnaround Time: %d\n", total_time);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &proc[i].priority);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].burst);
        proc[i].pid = i + 1;
    }

    // Perform priority scheduling
    priorityScheduling(proc, n);

    return 0;
}