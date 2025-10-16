#include <iostream>
using namespace std;

int main() {
    int n, m; // n = number of processes, m = number of resources
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    int alloc[10][10], maxNeed[10][10], avail[10];
    int need[10][10], finish[10], safeSeq[10];

    // Input Allocation Matrix
    cout << "\nEnter Allocation Matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i << ": ";
        for (int j = 0; j < m; j++) {
            cin >> alloc[i][j];
        }
    }

    // Input Maximum Need Matrix
    cout << "\nEnter Maximum Need Matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i << ": ";
        for (int j = 0; j < m; j++) {
            cin >> maxNeed[i][j];
        }
    }

    // Input Available Resources
    cout << "\nEnter Available Resources: ";
    for (int i = 0; i < m; i++) {
        cin >> avail[i];
    }

    // Calculate Need Matrix = Max - Allocation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = maxNeed[i][j] - alloc[i][j];
        }
    }

    // Initialize finish array to 0
    for (int i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int count = 0;

    // Main Safety Algorithm
    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) { // process not yet finished
                int j;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j])
                        break;
                }
                if (j == m) {
                    // Process can be allocated
                    for (int k = 0; k < m; k++) {
                        avail[k] += alloc[i][k];
                    }
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = true;
                }
            }
        }
        if (found == false) {
            cout << "\nSystem is NOT in safe state.";
            return 0;
        }
    }

    // If system is safe
    cout << "\nSystem is in SAFE state.\nSafe Sequence: ";
    for (int i = 0; i < n; i++) {
        cout << "P" << safeSeq[i];
        if (i != n - 1)
            cout << " -> ";
    }

    cout << endl;
    return 0;
}
\
