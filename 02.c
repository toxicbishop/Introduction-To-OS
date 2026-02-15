/* Simulate the following CPU scheduling algorithms to find turnaround time and waiting time
a) FCFS*/
#include <stdio.h>
#include <stdlib.h>
struct fcfs
{
    int pid;
    int btime;
    int wtime;
    int ttime;
};
int main()
{
    int i, n;
    int totwtime = 0, totttime = 0;
    printf("\nFCFS scheduling...\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct fcfs p[10];
    for (i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &p[i].btime);
    }
    p[0].wtime = 0;
    p[0].ttime = p[0].btime;
    totttime += p[0].ttime;
    for (i = 1; i < n; i++)
    {
        p[i].wtime = p[i - 1].wtime + p[i - 1].btime;
        p[i].ttime = p[i].wtime + p[i].btime;
        totttime += p[i].ttime;
        totwtime += p[i].wtime;
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t%d\t\t%d\t\t%d", p[i].pid, p[i].btime, p[i].wtime,
               p[i].ttime);
    }
    printf("\nTotal Waiting Time: %d", totwtime);
    printf("\nAverage Waiting Time: %f", (float)totwtime / n);
    printf("\nTotal Turnaround Time: %d", totttime);
    printf("\nAverage Turnaround Time: %f", (float)totttime / n);
    return 0;
}
// Output
/*FCFS scheduling ...
Enter the number of processes: 3
Enter the burst time of process 1: 6
Enter the burst time of process 2: 4
Enter the burst time of process 3: 8

Process	Burst Time	Waiting Time	Turnaround Time
1	6		0		6
2	4		6		10
3	8		10		18

Total Waiting Time: 16
Average Waiting Time: 5.333333
Total Turnaround Time: 34
Average Turnaround Time: 11.333333
*/

/*b) SJF*/
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int pid;   // Process ID
    int btime; // Burst time
    int wtime; // Waiting time
    int ttime; // Turnaround time
} sp;
int main()
{
    int i, j, n, tbm = 0, totwtime = 0, totttime;
    sp *p, t;
    printf("\nShortest Job First (SJF) scheduling...\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    p = (sp *)malloc(n * sizeof(sp));
    printf("\nEnter the burst time for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &p[i].btime);
        p[i].pid = i + 1;
        p[i].wtime = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].btime > p[j].btime)
            {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
    printf("\nProcess Scheduling\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        totwtime += p[i].wtime = tbm;
        p[i].ttime = p[i].wtime + p[i].btime;
        tbm += p[i].btime;
        printf("%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].btime, p[i].wtime, p[i].ttime);
    }
    totttime = tbm + totwtime;
    printf("\nTotal Waiting Time: %d", totwtime);
    printf("\nAverage Waiting Time: %f", (float)totwtime / n);
    printf("\nTotal Turnaround Time: %d", totttime);
    printf("\nAverage Turnaround Time: %f\n", (float)totttime / n);
    free(p);
    return 0;
}
/*Output
Shortest Job First (SJF) scheduling...
Enter the number of processes: 3

Enter the burst time for each process:
Process 1: 6
Process 2: 4
Process 3: 8

Process Scheduling
Process	Burst Time	Waiting Time	Turnaround Time
2	4		0		4
1	6		4		10
3	8		10		18

Total Waiting Time: 14
Average Waiting Time: 4.666667
Total Turnaround Time: 32
Average Turnaround Time: 10.666667
*/

/*c) Round Robin*/
#include <stdio.h>
#include <stdlib.h>
struct rr
{
    int pno, btime, sbtime, wtime, lst;
};
int main()
{
    struct rr p[10];
    int pp = -1, ts, flag, count, ptm = 0, i, n, twt = 0, totttime = 0;
    printf("\nRound Robin scheduling............");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time slice: ");
    scanf("%d", &ts);
    printf("Enter the burst time:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &p[i].btime);
        p[i].wtime = p[i].lst = 0;
        p[i].pno = i + 1;
        p[i].sbtime = p[i].btime;
    }
    printf("Scheduling....\n");
    do
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            count = p[i].btime;
            if (count > 0)
            {
                flag = 1; // There are still processes with burst time left

                count = (count >= ts) ? ts : count;
                printf("Process %d from %d to %d\n", p[i].pno, ptm, ptm + count);
                ptm += count;
                p[i].btime -= count;
                if (pp != i)
                {
                    pp = i;
                    p[i].wtime += ptm - p[i].lst - count;
                    p[i].lst = ptm;
                }
            }
        }
    } while (flag);
    totttime = ptm;
    printf("\nTotal Waiting Time: %d");
}
/*Output
Round Robin scheduling............
Enter the number of processes: 3
Enter the time slice: 4
Enter the burst time:
Process 1: 6
Process 2: 4
Process 3: 8
Scheduling....
Process 1 from 0 to 4
Process 2 from 4 to 8
Process 3 from 8 to 12
Process 1 from 12 to 14

Total Waiting Time: 10
Average Waiting Time: 3.333333
Total Turnaround Time: 24
Average Turnaround Time: 8.000000
*/

/*d) Priority Scheduling*/
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int pno;
    int pri;
    int btime;
    int wtime;
} sp;
int main()
{
    int i, j, n;
    int tbm = 0, totwtime = 0, totttime = 0;
    sp *p, t;
    printf("\nPRIORITY SCHEDULING\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    p = (sp *)malloc(n * sizeof(sp));
    printf("Enter the burst time and priority for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &p[i].btime, &p[i].pri);
        p[i].pno = i + 1;
        p[i].wtime = 0;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].pri > p[j].pri)
            {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        totwtime += p[i].wtime = tbm;
        tbm += p[i].btime;
        printf("%d\t%d\t\t%d\t\t%d\n", p[i].pno, p[i].btime, p[i].wtime,
               p[i].wtime + p[i].btime);
    }
    totttime = tbm + totwtime;
    printf("\nTotal Waiting Time: %d", totwtime);
    printf("\nAverage Waiting Time: %f", (float)totwtime / n);
    printf("\nTotal Turnaround Time: %d", totttime);
    printf("\nAverage Turnaround Time: %f\n", (float)totttime / n);
    free(p); // Don't forget to free the allocated memory.
    return 0;
}
/*Output
PRIORITY SCHEDULING
Enter the number of processes: 3
Enter the burst time and priority for each process:
Process 1: 6 2
Process 2: 4 1
Process 3: 8 3

Process	Burst Time	Waiting Time	Turnaround Time
2	4		0		4
1	6		4		10
3	8		10		18

Total Waiting Time: 14
Average Waiting Time: 4.666667
Total Turnaround Time: 32
Average Turnaround Time: 10.666667
*/