#include <iostream>
using namespace std;

int main() {
    int n, qt;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[10], at[10], bt[10], rt[10]; 
    int wt[10] = {0}, tat[10] = {0};
    bool completed[10] = {false};

    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter Arrival Time and Burst Time for Process " << pid[i] << ": ";
        cin >> at[i] >> bt[i];
        rt[i] = bt[i]; 
    }

    cout << "Enter Time Quantum: ";
    cin >> qt;

    int currentTime = 0, completedCount = 0;

    cout << "\nGantt Chart (Execution Order):\n";

    while(completedCount < n) {
        bool executed = false;

        for(int i = 0; i < n; i++) {
            if(rt[i] > 0 && at[i] <= currentTime) {
                executed = true;
                cout << "P" << pid[i] << " ";
                
                if(rt[i] <= qt) {
                    currentTime += rt[i];
                    rt[i] = 0;
                    tat[i] = currentTime - at[i];
                    wt[i] = tat[i] - bt[i];
                    completed[i] = true;
                    completedCount++;
                } else {
                    currentTime += qt;
                    rt[i] -= qt;
                }
            }
        }

        if(!executed) {
            currentTime++; 
        }
    }

    cout << "\n\nPID\tAT\tBT\tWT\tTAT\n";
    for(int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }

    float totalWT = 0, totalTAT = 0;
    for(int i = 0; i < n; i++) {
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    cout << "\nAverage Waiting Time = " << totalWT / n;
    cout << "\nAverage Turnaround Time = " << totalTAT / n << endl;

    return 0;
}

