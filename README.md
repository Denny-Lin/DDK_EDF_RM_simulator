# DDK_EDF_RM_Simulator

This project simulates two classic operating system scheduling algorithms:

- **EDF (Earliest Deadline First)**  
  Schedules tasks based on their deadlines: the task with the earliest deadline is executed first.  
  - Handles periodic and aperiodic tasks  
  - Dynamically determines execution order based on deadlines  
  - Useful for real-time systems with time-critical tasks

- **RM (Rate Monotonic)**  
  A fixed-priority scheduling algorithm where tasks with shorter periods get higher priority.  
  - Assigns static priorities based on task frequency  
  - Suitable for periodic real-time tasks  
  - Guarantees schedulability under certain CPU utilization limits

The simulator demonstrates task scheduling behavior, including preemption and task completion order, for both EDF and RM algorithms.

## References
* https://en.wikipedia.org/wiki/Earliest_deadline_first_scheduling
* https://en.wikipedia.org/wiki/Rate-monotonic_scheduling
* https://en.wikipedia.org/wiki/Earliest_deadline_first_scheduling
* https://en.wikipedia.org/wiki/Rate-monotonic_scheduling
