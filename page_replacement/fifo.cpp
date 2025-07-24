#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

void fifoPageReplacement(int pages[], int n, int capacity) {
    unordered_set<int> memory;           // Set to store current pages in memory
    queue<int> pageQueue;                // Queue to maintain FIFO order

    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        // If page is not present in memory (page fault)
        if (memory.find(page) == memory.end()) {
            // If memory is full, remove the oldest page
            if (memory.size() == capacity) {
                int oldestPage = pageQueue.front();
                pageQueue.pop();
                memory.erase(oldestPage);
            }

            // Add new page
            memory.insert(page);
            pageQueue.push(page);
            pageFaults++;

            cout << "Page " << page << " loaded → Page Fault\n";
        } else {
            cout << "Page " << page << " already in memory → No Page Fault\n";
        }
    }

    cout << "\nTotal Page Faults: " << pageFaults << endl;
}

int main() {
    int n, capacity;

    cout << "Enter number of pages: ";
    cin >> n;

    int pages[n];
    cout << "Enter the page reference string:\n";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter frame capacity: ";
    cin >> capacity;

    fifoPageReplacement(pages, n, capacity);

    return 0;
}
