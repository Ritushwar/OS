#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

void SSTF_DiskScheduling(vector<int>& requests, int head) {
    int n = requests.size();
    vector<bool> visited(n, false);
    int seekCount = 0;
    vector<int> seekSequence;

    cout << "\nDisk access order:\n";

    for (int i = 0; i < n; i++) {
        int minDistance = INT_MAX;
        int closestIndex = -1;

        // Find the unvisited request closest to current head
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int distance = abs(requests[j] - head);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestIndex = j;
                }
            }
        }

        visited[closestIndex] = true;
        seekSequence.push_back(requests[closestIndex]);
        seekCount += minDistance;
        cout << "Move from " << head << " to " << requests[closestIndex] << " → Seek = " << minDistance << endl;
        head = requests[closestIndex];
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

    SSTF_DiskScheduling(requests, head);

    return 0;
}
