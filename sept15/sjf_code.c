#include <stdio.h>

int main()
{
    int n, i;

    // Arrays to store information of each process
    int pid[20];        // Process ID
    int at[20];         // Arrival Time
    int bt[20];         // Burst Time
    int ct[20];         // Completion Time
    int tat[20];        // Turnaround Time
    int wt[20];         // Waiting Time

    // Stores whether a process is completed or not
    // 0 = Not completed
    // 1 = Completed
    int completed[20] = {0};

    int time = 0;       // Current CPU time
    int count = 0;      // Number of completed processes
    int shortest;       // Stores the index of shortest process

    // Variables for context switch
    int context_switch = 0;
    int previous = -1;  // No previous process initially

    // Variables to calculate averages
    float total_wt = 0;
    float total_tat = 0;


    // ------------------------------------------------
    // STEP 1: Take number of processes
    // ------------------------------------------------

    printf("Enter number of processes: ");
    scanf("%d", &n);


    // ------------------------------------------------
    // STEP 2: Take Arrival Time and Burst Time
    // ------------------------------------------------

    for(i = 0; i < n; i++)
    {
        // Assign Process ID
        pid[i] = i + 1;

        // Take Arrival Time
        printf("\nEnter Arrival Time of P%d: ", pid[i]);
        scanf("%d", &at[i]);

        // Take Burst Time
        printf("Enter Burst Time of P%d: ", pid[i]);
        scanf("%d", &bt[i]);
    }


    // ------------------------------------------------
    // STEP 3: SJF Scheduling
    // ------------------------------------------------

    // Continue until all processes are completed
    while(count < n)
    {
        // Initially, no process is selected
        shortest = -1;


        // Check all processes to find the shortest job
        for(i = 0; i < n; i++)
        {
            // Check whether the process:
            // 1. Is not completed
            // 2. Has already arrived
            if(completed[i] == 0 && at[i] <= time)
            {
                // Select the process having the
                // smallest Burst Time
                if(shortest == -1 || bt[i] < bt[shortest])
                {
                    shortest = i;
                }
            }
        }


        // ------------------------------------------------
        // STEP 4: If no process has arrived
        // ------------------------------------------------

        if(shortest == -1)
        {
            // CPU remains idle
            // Move the current time forward
            time++;
        }


        // ------------------------------------------------
        // STEP 5: Process is selected
        // ------------------------------------------------

        else
        {
            // If a process was already executed,
            // changing to another process is a
            // context switch
            if(previous != -1)
            {
                context_switch++;
            }

            // Store the current process as previous process
            previous = shortest;


            // ------------------------------------------------
            // STEP 6: Execute the selected process
            // ------------------------------------------------

            // SJF is non-preemptive,
            // so the process runs completely
            time = time + bt[shortest];


            // ------------------------------------------------
            // STEP 7: Calculate Completion Time
            // ------------------------------------------------

            ct[shortest] = time;


            // ------------------------------------------------
            // STEP 8: Calculate Turnaround Time
            // ------------------------------------------------

            // TAT = Completion Time - Arrival Time
            tat[shortest] = ct[shortest] - at[shortest];


            // ------------------------------------------------
            // STEP 9: Calculate Waiting Time
            // ------------------------------------------------

            // WT = Turnaround Time - Burst Time
            wt[shortest] = tat[shortest] - bt[shortest];


            // ------------------------------------------------
            // STEP 10: Mark process as completed
            // ------------------------------------------------

            completed[shortest] = 1;

            // Increase completed process count
            count++;


            // Add WT and TAT to calculate averages later
            total_wt = total_wt + wt[shortest];
            total_tat = total_tat + tat[shortest];
        }
    }


    // ------------------------------------------------
    // STEP 11: Display the result
    // ------------------------------------------------

    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i],
               at[i],
               bt[i],
               ct[i],
               tat[i],
               wt[i]);
    }


    // ------------------------------------------------
    // STEP 12: Display average Waiting Time
    // ------------------------------------------------

    printf("\nAverage Waiting Time = %.2f", total_wt / n);


    // ------------------------------------------------
    // STEP 13: Display average Turnaround Time
    // ------------------------------------------------

    printf("\nAverage Turnaround Time = %.2f", total_tat / n);


    // ------------------------------------------------
    // STEP 14: Display Context Switches
    // ------------------------------------------------

    printf("\nTotal Context Switches = %d\n", context_switch);


    return 0;
}
