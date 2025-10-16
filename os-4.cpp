#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[10], at[10], bt[10], pr[10]; 
    int ct[10], tat[10], wt[10];
    bool completed[10] = {false};

    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter Arrival Time, Burst Time, and Priority for Process " << pid[i] << ": ";
        cin >> at[i] >> bt[i] >> pr[i];
    }

    int currentTime = 0, completedCount = 0;

    while(completedCount < n) {
        int idx = -1;
        int highestPr = 10000; 

        for(int i = 0; i < n; i++) {
            if(at[i] <= currentTime && !completed[i]) {
                if(pr[i] < highestPr) {
                    highestPr = pr[i];
                    idx = i;
                }
                else if(pr[i] == highestPr && at[i] < at[idx]) {
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            ct[idx] = currentTime + bt[idx];      
            tat[idx] = ct[idx] - at[idx];          
            wt[idx] = tat[idx] - bt[idx];          

            completed[idx] = true;               
            currentTime = ct[idx];               
            completedCount++;
        } else {
            currentTime++; 
        }
    }

    cout << "\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << pr[i] << "\t"
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    float totalTAT = 0, totalWT = 0;
    for(int i = 0; i < n; i++) {
        totalTAT += tat[i];
        totalWT += wt[i];
    }

    cout << "\nAverage Turnaround Time = " << totalTAT / n;
    cout << "\nAverage Waiting Time = " << totalWT / n << endl;

    return 0;
}

