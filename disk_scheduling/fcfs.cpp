#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void FCFS_DiskScheduling(vector<int>& requests, int head) {
    int seekCount = 0;
    vector<int> seekSequence;

    cout << "\nDisk access order:\n";
    for (int i = 0; i < requests.size(); i++) {
        seekSequence.push_back(requests[i]);
        int distance = abs(requests[i] - head);
        seekCount += distance;
        cout << "Move from " << head << " to " << requests[i] << " → Seek = " << distance << endl;
        head = requests[i];
    }

    cout << "\nTotal Seek Operations = " << seekCount << endl;
    cout << "Seek Sequence: ";
    for (int track : seekSequence) {
        cout << track << " ";
    }
    cout << endl;
}

int main() {
    int n, head;

    cout << "Enter number of disk requests: ";
    cin >> n;

    vector<int> requests(n);
    cout << "Enter disk request sequence:\n";
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
    }

    cout << "Enter initial head position: ";
    cin >> head;

    FCFS_DiskScheduling(requests, head);

    return 0;
}
