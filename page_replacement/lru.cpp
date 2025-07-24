#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

void lruPageReplacement(int pages[], int n, int capacity) {
    list<int> pageList;  // Doubly linked list to track LRU order
    unordered_map<int, list<int>::iterator> pageMap;  // Page -> iterator in list

    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        // If page is not in memory
        if (pageMap.find(page) == pageMap.end()) {
            if (pageList.size() == capacity) {
                // Remove least recently used page
                int lru = pageList.back();
                pageList.pop_back();
                pageMap.erase(lru);
            }

            // Add the new page to the front (most recently used)
            pageList.push_front(page);
            pageMap[page] = pageList.begin();
            pageFaults++;

            cout << "Page " << page << " loaded → Page Fault\n";
        } else {
            // Page is already in memory, move to front (most recently used)
            pageList.erase(pageMap[page]);
            pageList.push_front(page);
            pageMap[page] = pageList.begin();

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

    lruPageReplacement(pages, n, capacity);

    return 0;
}
