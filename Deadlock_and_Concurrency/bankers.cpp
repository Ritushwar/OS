#include <iostream> 

#include <vector> 

#include <string> 

  

using namespace std; 

  

bool is_safe_state(vector<string>& processes, vector<int>& avail, 

                   vector<vector<int>>& max_need, vector<vector<int>>& alloc, 

                   vector<string>& safe_seq) { 

    int n = processes.size(); 

    int m = avail.size(); 

  

    vector<vector<int>> need(n, vector<int>(m));						  

    for (int i = 0; i < n; ++i) 

        for (int j = 0; j < m; ++j) 

            need[i][j] = max_need[i][j] - alloc[i][j]; 

  

    vector<bool> finish(n, false); 

    vector<int> work = avail; 

  

    while (safe_seq.size() < n) { 

        bool found = false; 

        for (int i = 0; i < n; ++i) { 

            if (!finish[i]) { 

                bool can_allocate = true; 

                for (int j = 0; j < m; ++j) { 

                    if (need[i][j] > work[j]) { 

                        can_allocate = false; 

                        break; 

                    } 

                } 

                if (can_allocate) { 

                    for (int j = 0; j < m; ++j) 

                        work[j] += alloc[i][j]; 

                    safe_seq.push_back(processes[i]); 

                    finish[i] = true; 

                    found = true; 

                    break; 

                } 

            } 

        } 

        if (!found) 

            return false; 

    } 

  

    return true; 

} 

  

int main() { 

    int n, m; 

    cout << "Enter number of processes: "; 

    cin >> n; 

    cout << "Enter number of resource types: "; 

    cin >> m; 

  

    vector<string> processes(n);								  

    for (int i = 0; i < n; ++i) 

        processes[i] = "P" + to_string(i); 

  

    cout << "\nEnter Allocation Matrix:\n"; 

    vector<vector<int>> alloc(n, vector<int>(m)); 

    for (int i = 0; i < n; ++i) { 

        cout << "Allocation for " << processes[i] << ": "; 

        for (int j = 0; j < m; ++j) 

            cin >> alloc[i][j]; 

    } 

  

    cout << "\nEnter Maximum Matrix:\n"; 

    vector<vector<int>> max_need(n, vector<int>(m)); 

    for (int i = 0; i < n; ++i) { 

        cout << "Maximum need for " << processes[i] << ": "; 

        for (int j = 0; j < m; ++j) 

            cin >> max_need[i][j]; 

    } 

  

    cout << "\nEnter Available Resources: "; 

    vector<int> avail(m); 

    for (int j = 0; j < m; ++j) 

        cin >> avail[j]; 

  

    cout << "\nChecking system state...\n"; 

  

    vector<string> safe_seq; 

    if (is_safe_state(processes, avail, max_need, alloc, safe_seq)) { 

        cout << "System is in a SAFE state.\n"; 

        cout << "Safe sequence: "; 

        for (size_t i = 0; i < safe_seq.size(); ++i) { 

            cout << safe_seq[i]; 

            if (i < safe_seq.size() - 1) 

                cout << " -> "; 

        } 

        cout << endl; 

    } else { 

        cout << "System is in an UNSAFE state! Deadlock may occur.\n"; 

    } 

  

    return 0; 

}
