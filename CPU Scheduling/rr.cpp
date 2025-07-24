#include <iostream>
#include <queue>
#include <vector>
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
    int n, time_quantum;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    queue<int> ready_queue;

    for (int i = 0; i < n; ++i) {
        processes[i].pid = i + 1;
        cout << "Enter arrival time for P" << i + 1 << ": ";
        cin >> processes[i].arrival_time;
        cout << "Enter burst time for P" << i + 1 << ": ";
        cin >> processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
    }

    cout << "Enter Time Quantum: ";
    cin >> time_quantum;

    int current_time = 0;
    int completed = 0;
    vector<bool> in_queue(n, false);
    vector<int> gantt_chart;

    // Enqueue the first arriving process(es)
    for (int i = 0; i < n; ++i) {
        if (processes[i].arrival_time == 0) {
            ready_queue.push(i);
            in_queue[i] = true;
        }
    }

    while (completed < n) {
        if (!ready_queue.empty()) {
            int idx = ready_queue.front();
            ready_queue.pop();

            int exec_time = min(time_quantum, processes[idx].remaining_time);
            gantt_chart.push_back(processes[idx].pid);

            current_time += exec_time;
            processes[idx].remaining_time -= exec_time;

            // Add newly arrived processes to the queue
            for (int i = 0; i < n; ++i) {
                if (!in_queue[i] && processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                    ready_queue.push(i);
                    in_queue[i] = true;
                }
            }

            // Re-add this process if it's not done
            if (processes[idx].remaining_time > 0) {
                ready_queue.push(idx);
            } else {
                processes[idx].completion_time = current_time;
                processes[idx].turnaround_time = processes[idx].completion_time - processes[idx].arrival_time;
                processes[idx].waiting_time = processes[idx].turnaround_time - processes[idx].burst_time;
                completed++;
            }
        } else {
            // If queue is empty, increment time (idle)
            current_time++;
            // Check for newly arriving processes
            for (int i = 0; i < n; ++i) {
                if (!in_queue[i] && processes[i].arrival_time <= current_time) {
                    ready_queue.push(i);
                    in_queue[i] = true;
                }
            }
        }
    }

    // Gantt chart
    cout << "\nGantt Chart:\n| ";
    for (int pid : gantt_chart) {
        cout << "P" << pid << " | ";
    }

    // Results
    float total_wait = 0, total_turnaround = 0;
    cout << "\n\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (auto &p : processes) {
        cout << "P" << p.pid << "\t" << p.arrival_time << "\t" << p.burst_time
             << "\t" << p.waiting_time << "\t" << p.turnaround_time << "\n";
        total_wait += p.waiting_time;
        total_turnaround += p.turnaround_time;
    }

    cout << "\nAverage Waiting Time: " << total_wait / n;
    cout << " \nAverage Turnaround Time: " << total_turnaround / n << "\n";

    return 0;
}
