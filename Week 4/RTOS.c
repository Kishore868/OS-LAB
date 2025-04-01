
#include <stdio.h>

#define MAX_TASKS 10

// Task structure: holds execution time and period
typedef struct {
    int id;         // Task ID
    int execution;  // Execution time of the task (C)
    int period;     // Period of the task (T)
} Task;

// Function to compare tasks based on their period (shorter period gets higher priority)
void sort_by_priority(Task tasks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tasks[i].period > tasks[j].period) {
                // Swap tasks[i] and tasks[j]
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

// Function to simulate Rate Monotonic Scheduling
void rate_monotonic(Task tasks[], int n) {
    int time = 0;
    int completed = 0;

    // Simple time-driven loop to simulate task execution
    while (completed < n) {
        int task_executed = -1;

        // Find the highest priority task (shortest period)
        for (int i = 0; i < n; i++) {
            if (time % tasks[i].period == 0) {
                task_executed = i;
                break;
            }
        }

        // If a task is ready to execute, run it
        if (task_executed != -1) {
            printf("At time %d: Task %d is executed\n", time, tasks[task_executed].id);
            time += tasks[task_executed].execution;  // Increase time by execution time of the task
            completed++;  // Mark this task as completed
        } else {
            time++;  // If no task is ready, move time forward
        }
    }
}

int main() {
    int n;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    // Create an array of tasks
    Task tasks[n];

    // Input task details (execution time and period)
    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        printf("\nEnter details for Task %d\n", i + 1);
        printf("Execution time (C): ");
        scanf("%d", &tasks[i].execution);
        printf("Period (T): ");
        scanf("%d", &tasks[i].period);
    }

    // Sort tasks by their period (Rate Monotonic Scheduling rule)
    sort_by_priority(tasks, n);

    // Run the rate monotonic scheduler
    rate_monotonic(tasks, n);

    return 0;
}
