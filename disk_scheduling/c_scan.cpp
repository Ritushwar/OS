#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void CSCAN_DiskScheduling(vector<int>& requests, int head, int diskSize) {
    vector<int> left, right;
    int seekCount = 0;
    vector<int> seekSequence;

    // Requests on the right and left of head
    for (int i = 0; i < requests.size(); i++) {
        if (requests[i] >= head)
            right.push_back(requests[i]);
        else
            left.push_back(requests[i]);
    }

    // Add end points
    right.push_back(diskSize - 1); // simulate moving to end
    left.push_back(0);             // simulate jumping to start

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    cout << "\nDisk access order (C-SCAN):\n";

    // Service the right side
    for (int i = 0; i < right.size(); i++) {
        seekSequence.push_back(right[i]);
        int distance = abs(head - right[i]);
        seekCount += distance;
        cout << "Move from " << head << " to " << right[i] << " → Seek = " << distance << endl;
        head = right[i];
    }

    // Jump from end to start
    cout << "Jump from " << head << " to 0 → Seek = " << head << endl;
    seekCount += head;
    head = 0;

    // Service the left side
    for (int i = 0; i < left.size(); i++) {
        seekSequence.push_back(left[i]);
        int distance = abs(head - left[i]);
        seekCount += distance;
        cout << "Move from " << head << " to " << left[i] << " → Seek = " << distance << endl;
        head = left[i];
    }

    cout << "\nTotal Seek Operations = " << seekCount << endl;
    cout << "Seek Sequence: ";
    for (int track : seekSequence) {
        cout << track << " ";
    }
    cout << endl;
}

int main() {
    int n, head, diskSize;

    cout << "Enter number of disk requests: ";
    cin >> n;

    vector<int> requests(n);
    cout << "Enter disk request sequence:\n";
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
    }

    cout << "Enter initial head position: ";
    cin >> head;

    cout << "Enter total disk size (max cylinder number): ";
    cin >> diskSize;

    CSCAN_DiskScheduling(requests, head, diskSize);

    return 0;
}
