#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
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
        processes[i].remaining_time = processes[i].burst_time;
    }

    int complete = 0, current_time = 0;
    int shortest = -1;
    bool found = false;

    vector<int> gantt_chart;

    while (complete != n) {
        int min_remain = INT_MAX;
        found = false;

        for (int i = 0; i < n; ++i) {
            if (processes[i].arrival_time <= current_time &&
                processes[i].remaining_time > 0 &&
                processes[i].remaining_time < min_remain) {
                min_remain = processes[i].remaining_time;
                shortest = i;
                found = true;
            }
        }

        if (!found) {
            gantt_chart.push_back(-1);  // CPU is idle
            current_time++;
            continue;
        }

        processes[shortest].remaining_time--;
        gantt_chart.push_back(processes[shortest].pid);

        if (processes[shortest].remaining_time == 0) {
            complete++;
            processes[shortest].completion_time = current_time + 1;
            processes[shortest].turnaround_time = processes[shortest].completion_time - processes[shortest].arrival_time;
            processes[shortest].waiting_time = processes[shortest].turnaround_time - processes[shortest].burst_time;
        }

        current_time++;
    }

    // Gantt chart
    cout << "\nGantt Chart:\n| ";
    for (int i = 0; i < gantt_chart.size(); ++i) {
        if (gantt_chart[i] == -1)
            cout << "Idle | ";
        else
            cout << "P" << gantt_chart[i] << " | ";
    }

    cout << "\n\nProcess\tArrival\tBurst\tWaiting\tTurnaround";
    float total_wait = 0, total_turnaround = 0;

    for (auto &p : processes) {
        cout << "\nP" << p.pid << "\t" << p.arrival_time << "\t" << p.burst_time
             << "\t" << p.waiting_time << "\t" << p.turnaround_time;
        total_wait += p.waiting_time;
        total_turnaround += p.turnaround_time;
    }

    cout << "\n\nAverage Waiting Time: " << total_wait / n;
    cout << "\nAverage Turnaround Time: " << total_turnaround / n << "\n";

    return 0;
}
