#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; ++i) {
        processes[i].pid = i + 1;
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> processes[i].arrival_time;
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> processes[i].burst_time;
    }

    // Sort based on arrival time
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.arrival_time < b.arrival_time;
    });

    int current_time = 0;
    float total_waiting_time = 0, total_turnaround_time = 0;

    cout << "\nGantt Chart:\n";
    for (auto &p : processes) {
        if (current_time < p.arrival_time)
            current_time = p.arrival_time;

        p.waiting_time = current_time - p.arrival_time;
        p.turnaround_time = p.waiting_time + p.burst_time;

        total_waiting_time += p.waiting_time;
        total_turnaround_time += p.turnaround_time;

        cout << "| P" << p.pid << " ";
        current_time += p.burst_time;
    }
    cout << "|\n";

    cout << "\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (auto &p : processes) {
        cout << "P" << p.pid << "\t" << p.arrival_time << "\t" << p.burst_time
             << "\t" << p.waiting_time << "\t" << p.turnaround_time << "\n";
    }

    cout << "\nAverage waiting time: " << total_waiting_time / n;
    cout << "\nAverage turnaround time: " << total_turnaround_time / n << "\n";

    return 0;
}
