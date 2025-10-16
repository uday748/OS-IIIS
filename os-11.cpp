#include <iostream>
using namespace std;

int main() {
    int n, frames;
    cout << "Enter number of pages: ";
    cin >> n;

    int pages[50];
    cout << "Enter page reference sequence: ";
    for(int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> frames;

    int memory[10];  
    int time[10];     
    for(int i = 0; i < frames; i++) {
        memory[i] = -1; 
        time[i] = -1;   
    }

    int pageFaults = 0;

    cout << "\nPage Replacement Process:\n";
    for(int i = 0; i < n; i++) {
        bool found = false;

        
        for(int j = 0; j < frames; j++) {
            if(memory[j] == pages[i]) {
                found = true;
                time[j] = i; 
                break;
            }
        }

        if(!found) {
            pageFaults++;

            int lruIndex = 0;
            int minTime = 1e9;

            for(int j = 0; j < frames; j++) {
                if(memory[j] == -1) {
                    lruIndex = j;
                    break;
                }
                if(time[j] < minTime) {
                    minTime = time[j];
                    lruIndex = j;
                }
            }

            memory[lruIndex] = pages[i];
            time[lruIndex] = i;
        }

        cout << "After accessing page " << pages[i] << ": ";
        for(int j = 0; j < frames; j++) {
            if(memory[j] != -1)
                cout << memory[j] << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }

    cout << "\nTotal Page Faults = " << pageFaults << endl;

    return 0;
}

