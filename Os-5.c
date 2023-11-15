#include <stdio.h>

typedef struct {
    int process_id;
    int priority;
    int burst_time;
} Process;

void swap(Process *xp, Process *yp) {
    Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort_by_priority(Process processes[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter priority and burst time for Process %d: ", i + 1);
        scanf("%d %d", &processes[i].priority, &processes[i].burst_time);
    }

    sort_by_priority(processes, n);

    printf("\nExecution Order:\n");
    printf("Process\tPriority\tBurst Time\n");

    int total_time = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", processes[i].process_id, processes[i].priority, processes[i].burst_time);
        total_time += processes[i].burst_time;
    }

    printf("\nTotal Execution Time: %d\n", total_time);

    return 0;
}
