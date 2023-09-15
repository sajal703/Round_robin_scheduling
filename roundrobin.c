#include <stdio.h>

int main() {
  int n, burst_time[100], arrival_time[100], quantum;
  float turnaround_time[100], waiting_time[100];

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("Enter the arrival time and burst time for process %d: ", i + 1);
    scanf("%d %d", &arrival_time[i], &burst_time[i]);
  }

  printf("Enter the time quantum: ");
  scanf("%d", &quantum);

  for (int i = 0; i < n; i++) {
    turnaround_time[i] = burst_time[i];
    waiting_time[i] = 0;
  }

  int current_time = 0;
  while (1) {
    int process_to_execute = -1;
    for (int i = 0; i < n; i++) {
      if (arrival_time[i] <= current_time && burst_time[i] > 0) {
        process_to_execute = i;
        break;
      }
    }

    if (process_to_execute == -1) {
      break;
    }

    int time_left = (burst_time[process_to_execute] > quantum) ? quantum : burst_time[process_to_execute];
    burst_time[process_to_execute] -= time_left;
    waiting_time[process_to_execute] += (current_time - arrival_time[process_to_execute]);
    current_time += time_left;

    if (burst_time[process_to_execute] == 0) {
      turnaround_time[process_to_execute] = current_time;
    }
  }

  float average_turnaround_time = 0.0;
  float average_waiting_time = 0.0;
  for (int i = 0; i < n; i++) {
    average_turnaround_time += turnaround_time[i];
    average_waiting_time += waiting_time[i];
  }

  average_turnaround_time /= n;
  average_waiting_time /= n;

  printf("Average turnaround time: %f\n", average_turnaround_time);
  printf("Average waiting time: %f\n", average_waiting_time);

  return 0;
}