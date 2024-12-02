# CPU Scheduling Algorithm - Hybrid Round Robin (RR) and Shortest Job First (SJF)

## Overview
This project implements a hybrid CPU scheduling algorithm that combines the Round Robin (RR) and Shortest Job First (SJF) techniques. The hybrid approach aims to improve process scheduling by balancing response time and throughput.

## Features:
- Input: Processes with burst times.
- Output: Gantt chart, average waiting time, and average turn-around time.

## Running the Code
1. Compile the C++ code using `g++`.
2. Run the executable and provide the necessary inputs for process IDs and burst times.
3. Observe the scheduling results, including the Gantt chart and performance metrics.

## Example Input:
- Processes: P1, P2, P3
- Burst times: 10, 5, 8

## Example Output:
- Gantt Chart: [P2, P3, P1]
- Average Waiting Time: 4.5 ms
- Average Turnaround Time: 7.33 ms
