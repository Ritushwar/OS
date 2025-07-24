#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int predict(int pages[], int n, int index, unordered_set<int>& memory) {
    int res = -1, farthest = index;
    for (int page : memory) {
        int j;
        for (j = index; j < n; j++) {
            if (pages[j] == page) {
                if (j > farthest) {
                    farthest = j;
                    res = page;
                }
                break;
            }
        }
        // If page not found in future, return immediately
        if (j == n) {
            return page;
        }
    }
    // If all pages are going to be used again, return the farthest used one
    if (res == -1) {
        // If all pages used immediately again, pick any (e.g., first in memory)
        return *memory.begin();
    }
    return res;
}

void optimalPageReplacement(int pages[], int n, int capacity) {
    unordered_set<int> memory;
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        // If page is not already in memory
        if (memory.find(pages[i]) == memory.end()) {
            // If memory is full, replace a page
            if ((int)memory.size() == capacity) {
                int pageToRemove = predict(pages, n, i + 1, memory);
                memory.erase(pageToRemove);
            }
            // Insert the current page
            memory.insert(pages[i]);
            pageFaults++;
            cout << "Page " << pages[i] << " loaded → Page Fault\n";
        } else {
            cout << "Page " << pages[i] << " already in memory → No Page Fault\n";
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

    optimalPageReplacement(pages, n, capacity);

    return 0;
}
