#include <stdio.h>

int main() {
    int n, i, j;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], bt[n], priority[n], wt[n], tat[n];

    // Input burst time and priority
    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Burst Time and Priority for Process %d: ", pid[i]);
        scanf("%d %d", &bt[i], &priority[i]);
    }

    // Sort processes based on priority (ascending order)
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(priority[i] > priority[j]) {
                // Swap priority
                int temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process IDs
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Calculate waiting time
    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate turnaround time and averages
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    avgWT /= n;
    avgTAT /= n;

    // Display results
    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\t%d\n", pid[i], bt[i], priority[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);

    return 0;
}

