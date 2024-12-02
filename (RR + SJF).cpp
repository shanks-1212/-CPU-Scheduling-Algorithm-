#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Structure to represent a process
struct Process {
    int id;          // Process ID
    int burstTime;   // Burst time (CPU time required)
    int waitingTime; // Waiting time
    int turnAroundTime; // Turnaround time
    int remainingTime;  // Remaining time (for RR)
};

// Function to implement Round Robin (RR) scheduling
void roundRobinScheduling(vector<Process>& processes, int timeQuantum) {
    queue<Process*> processQueue;

    // Initialize remaining times and add processes to the queue
    for (auto& process : processes) {
        process.remainingTime = process.burstTime;
        process.waitingTime = 0;
        process.turnAroundTime = 0;
        processQueue.push(&process);
    }

    int time = 0;
    while (!processQueue.empty()) {
        Process* currentProcess = processQueue.front();
        processQueue.pop();

        if (currentProcess->remainingTime > timeQuantum) {
            currentProcess->remainingTime -= timeQuantum;
            time += timeQuantum;
            processQueue.push(currentProcess);
        } else {
            time += currentProcess->remainingTime;
            currentProcess->waitingTime = time - currentProcess->burstTime;
            currentProcess->turnAroundTime = time;
            currentProcess->remainingTime = 0;
        }
    }
}

// Function to implement Shortest Job First (SJF) scheduling
void shortestJobFirstScheduling(vector<Process>& processes) {
    // Sort processes by burst time
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.burstTime < b.burstTime;
    });

    int time = 0;
    for (auto& process : processes) {
        process.waitingTime = time;
        process.turnAroundTime = time + process.burstTime;
        time += process.burstTime;
    }
}

// Function to calculate average waiting and turnaround times
void calculateAverageTimes(const vector<Process>& processes) {
    double totalWaitingTime = 0, totalTurnAroundTime = 0;
    for (const auto& process : processes) {
        totalWaitingTime += process.waitingTime;
        totalTurnAroundTime += process.turnAroundTime;
    }
    int n = processes.size();
    cout << "Average Waiting Time: " << totalWaitingTime / n << endl;
    cout << "Average Turnaround Time: " << totalTurnAroundTime / n << endl;
}

// Main function for Hybrid Scheduling: RR + SJF
void hybridScheduling(vector<Process>& processes, int timeQuantum) {
    // First apply Round Robin
    roundRobinScheduling(processes, timeQuantum);
    
    // Then apply Shortest Job First
    shortestJobFirstScheduling(processes);
}

 
