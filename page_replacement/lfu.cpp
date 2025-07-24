#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

struct Page {
    int number;
    int frequency;
    int time; // To break ties using FIFO when frequencies are equal
};

struct Compare {
    bool operator()(const Page& a, const Page& b) const {
        if (a.frequency == b.frequency)
            return a.time < b.time; // Break tie with oldest page
        return a.frequency < b.frequency;
    }
};

void lfuPageReplacement(int pages[], int n, int capacity) {
    unordered_map<int, Page> pageTable; // page -> Page struct
    set<Page, Compare> cache;           // Ordered by frequency, then time

    int time = 0, pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int pageNum = pages[i];
        time++;

        auto it = pageTable.find(pageNum);

        // If page is not in memory
        if (it == pageTable.end()) {
            if ((int)pageTable.size() == capacity) {
                // Remove LFU page (begin of set)
                Page lfu = *cache.begin();
                cache.erase(cache.begin());
                pageTable.erase(lfu.number);
            }

            // Insert new page
            Page newPage = {pageNum, 1, time};
            cache.insert(newPage);
            pageTable[pageNum] = newPage;
            pageFaults++;

            cout << "Page " << pageNum << " loaded → Page Fault\n";
        } else {
            // Update frequency and time
            Page updatedPage = it->second;
            cache.erase(updatedPage); // Remove outdated record
            updatedPage.frequency++;
            updatedPage.time = time;
            cache.insert(updatedPage);
            pageTable[pageNum] = updatedPage;

            cout << "Page " << pageNum << " already in memory → No Page Fault\n";
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

    lfuPageReplacement(pages, n, capacity);

    return 0;
}
