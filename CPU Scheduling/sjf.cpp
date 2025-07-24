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
    bool completed = false;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; ++i) {
        processes[i].pid = i + 1;
        cout << "Enter arrival time for P" << i + 1 << ": ";
        cin >> processes[i].arrival_time;
        cout << "Enter burst time for P" << i + 1 << ": ";
        cin >> processes[i].burst_time;
    }

    int current_time = 0, completed = 0;
    float total_waiting_time = 0, total_turnaround_time = 0;

    cout << "\nGantt Chart:\n";

    while (completed < n) {
        int idx = -1;
        int min_burst = 1e9;

        for (int i = 0; i < n; ++i) {
            if (!processes[i].completed && processes[i].arrival_time <= current_time) {
                if (processes[i].burst_time < min_burst) {
                    min_burst = processes[i].burst_time;
                    idx = i;
                } else if (processes[i].burst_time == min_burst) {
                    // If burst time is same, choose process with earlier arrival
                    if (processes[i].arrival_time < processes[idx].arrival_time)
                        idx = i;
                }
            }
        }

        if (idx != -1) {
            Process &p = processes[idx];
            p.waiting_time = current_time - p.arrival_time;
            if (p.waiting_time < 0) p.waiting_time = 0;

            current_time += p.burst_time;
            p.turnaround_time = p.waiting_time + p.burst_time;
            p.completed = true;
            completed++;

            total_waiting_time += p.waiting_time;
            total_turnaround_time += p.turnaround_time;

            cout << "| P" << p.pid << " ";
        } else {
            // No process has arrived yet
            current_time++;
        }
    }

    cout << "|\n";

    cout << "\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (auto &p : processes) {
        cout << "P" << p.pid << "\t" << p.arrival_time << "\t" << p.burst_time
             << "\t" << p.waiting_time << "\t" << p.turnaround_time << "\n";
    }

    cout << "\nAverage Waiting Time: " << total_waiting_time / n;
    cout << "\nAverage Turnaround Time: " << total_turnaround_time / n << "\n";

    return 0;
}
