#include <iostream>
using namespace std;

int main() {
    int n, m; 
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    int max[10][10], allocation[10][10], need[10][10];
    int available[10];
    bool finished[10] = {false};

    cout << "Enter Max matrix:\n";
    for(int i = 0; i < n; i++) {
        cout << "Process " << i+1 << ": ";
        for(int j = 0; j < m; j++)
            cin >> max[i][j];
    }

    cout << "Enter Allocation matrix:\n";
    for(int i = 0; i < n; i++) {
        cout << "Process " << i+1 << ": ";
        for(int j = 0; j < m; j++)
            cin >> allocation[i][j];
    }

    cout << "Enter Available resources: ";
    for(int j = 0; j < m; j++)
        cin >> available[j];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
    }


    int safeSeq[10], count = 0;
    bool found;
    while(count < n) {
        found = false;
        for(int i = 0; i < n; i++) {
            if(!finished[i]) {
                bool canAllocate = true;
                for(int j = 0; j < m; j++) {
                    if(need[i][j] > available[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if(canAllocate) {
                    for(int j = 0; j < m; j++)
                        available[j] += allocation[i][j];
                    safeSeq[count++] = i+1; 
                    finished[i] = true;
                    found = true;
                }
            }
        }
        if(!found) break; 
    }

    if(count == n) {
        cout << "\nSystem is in a SAFE state.\nSafe sequence: ";
        for(int i = 0; i < n; i++)
            cout << "P" << safeSeq[i] << " ";
        cout << endl;
    } else {
        cout << "\nSystem is in an UNSAFE state. Deadlock may occur.\n";
    }

    return 0;
}

