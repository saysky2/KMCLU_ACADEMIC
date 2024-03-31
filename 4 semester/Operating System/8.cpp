// SJF scheduling algorithm
#include <stdio.h>

// Structure to represent a process with Process ID and Burst time
struct Process {
    int pid;    // Process ID
    int burst;  // Burst time
};

// Function to implement Shortest Job First scheduling algorithm
void SJF(struct Process proc[], int n) {
    int total_time = 0;     // Variable to track total time
    int waiting_time = 0;   // Variable to track waiting time

    // Sorting processes based on burst time using Bubble Sort algorithm
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].burst > proc[j].burst) {
                struct Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }

    // Printing header for process details table
    printf("Process ID\tBurst Time\tWaiting Time\n");

    // Loop to print process details and update time variables
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst, waiting_time);
        total_time += waiting_time + proc[i].burst;
        waiting_time += proc[i].burst;
    }

    // Calculating average waiting time
    float avg_waiting_time = (float)waiting_time / n;

    // Printing average waiting time
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);

    // Printing total turnaround time
    printf("Total Turnaround Time: %d\n", total_time);
}

int main() {
    int n;

    // Prompting user to input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];  // Declaring an array of processes

    // Loop to input burst time for each process
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].burst);
        proc[i].pid = i + 1;
    }

    SJF(proc, n);  // Calling SJF function to perform Shortest Job First scheduling

    return 0;  // Indicating successful completion of program
}