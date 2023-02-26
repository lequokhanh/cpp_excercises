#include <bits/stdc++.h>

using namespace std;

struct Process
{
    int pid;
    int arr, burst, remain, start, finish, RT, TAT, WT;
    bool isNew;
};

int main()
{
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int number_process;
    vector<Process> processes;
    cout << "Enter number of processes: ";
    cin >> number_process;
    for (int i = 0; i < number_process; i++)
    {
        Process process;
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> process.arr;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> process.burst;
        process.pid = i + 1;
        process.isNew = true;
        process.remain = process.burst;
        processes.push_back(process);
    }
    sort(processes.begin(), processes.end(), [](Process a, Process b)
         { return a.arr < b.arr; });
    queue<Process> new_processes;
    for (auto process : processes)
        new_processes.push(process);
    int time = 0;
    deque<Process> ready_queue;
    vector<Process> terminated_processes;
    while (terminated_processes.size() != number_process)
    {
        while (!new_processes.empty() && new_processes.front().arr <= time)
        {
            ready_queue.push_back(new_processes.front());
            new_processes.pop();
        }
        if (ready_queue.empty())
        {
            time = new_processes.front().arr;
            continue;
        }
        sort(ready_queue.begin(), ready_queue.end(), [](Process a, Process b)
             { return a.remain < b.remain; });
        Process current_process = ready_queue.front();
        ready_queue.pop_front();
        if (current_process.isNew)
        {
            current_process.start = time;
            current_process.isNew = false;
        }
        if (new_processes.empty())
        {
            time += current_process.remain;
            current_process.remain = 0;
        }
        else
        {
            if (current_process.remain <= new_processes.front().arr - time)
            {
                time += current_process.remain;
                current_process.remain = 0;
            }
            else
            {
                current_process.remain -= new_processes.front().arr - time;
                time = new_processes.front().arr;
            }
        }
        if (current_process.remain == 0)
        {
            current_process.finish = time;
            current_process.TAT = current_process.finish - current_process.arr;
            current_process.WT = current_process.TAT - current_process.burst;
            current_process.RT = current_process.start - current_process.arr;
            terminated_processes.push_back(current_process);
        }
        else
            ready_queue.push_back(current_process);
    }
    int sum_TAT = 0, sum_WT = 0, sum_RT = 0;
    sort(terminated_processes.begin(), terminated_processes.end(), [](Process a, Process b)
         { return a.pid <= b.pid; });
    cout << "PID\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\tResponse Time\n";
    for (auto process : terminated_processes)
    {
        cout << process.pid << "\t" << process.arr << "\t\t" << process.burst << "\t\t" << process.TAT << "\t\t" << process.WT << "\t\t" << process.RT << endl;
        sum_TAT += process.TAT;
        sum_WT += process.WT;
        sum_RT += process.RT;
    }
    float avg_TAT = (float)sum_TAT / number_process,
          avg_WT = (float)sum_WT / number_process,
          avg_RT = (float)sum_RT / number_process;
    cout << "Average Turnaround Time: " << avg_TAT << endl;
    cout << "Average Waiting Time: " << avg_WT << endl;
    cout << "Average Response Time: " << avg_RT << endl;
}