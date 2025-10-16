#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];
    
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter Arrival Time and Burst Time for Process " << pid[i] << ": ";
        cin >> at[i] >> bt[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }

    ct[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++) {
        if (at[i] > ct[i - 1])
            ct[i] = at[i] + bt[i];  
        else
            ct[i] = ct[i - 1] + bt[i];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t" << at[i] << "\t" << bt[i]
             << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
    }

    float totalTAT = 0, totalWT = 0;
    for (int i = 0; i < n; i++) {
        totalTAT += tat[i];
        totalWT += wt[i];
    }

    cout << "\nAverage Turnaround Time = " << totalTAT / n;
    cout << "\nAverage Waiting Time = " << totalWT / n << endl;

    return 0;
}

