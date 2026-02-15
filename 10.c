/*Develop a C program to simulate SCAN disk scheduling algorithm.*/
#include <stdio.h>
int absoluteValue(int);
void main()
{
    int queue[25], n, headposition, i, j, k, seek = 0, maxrange,
                                             difference, temp, queue1[20], queue2[20], temp1 = 0, temp2 = 0;
    float averageSeekTime;
    printf("Enter the maximum range of Disk: ");
    scanf("%d", &maxrange);
    printf("Enter the number of queue requests: ");
    scanf("%d", &n);
    printf("Enter the initial head position: ");
    scanf("%d", &headposition);
    // Reading disk positions to be read in the order of arrival
    printf("Enter the disk positions to be read(queue): ");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        if (temp > headposition)
        {
            queue1[temp1] = temp;
            temp1++;
        }
        else
        {
            queue2[temp2] = temp;
            temp2++;
        }
    }

    for (i = 0; i < temp1 - 1; i++)
    {
        for (j = i + 1; j < temp1; j++)
        {
            if (queue1[i] > queue1[j])
            {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
        }
    }

    for (i = 0; i < temp2 - 1; i++)
    {
        for (j = i + 1; j < temp2; j++)
        {
            if (queue2[i] < queue2[j])
            {
                temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }
        }
    }

    for (i = 1, j = 0; j < temp1; i++, j++)
    {
        queue[i] = queue1[j];
    }

    queue[i] = maxrange;
    for (i = temp1 + 2, j = 0; j < temp2; i++, j++)
    {
        queue[i] = queue2[j];
    }

    queue[i] = 0;
    queue[0] = headposition;
    for (j = 0; j <= n; j++) // Loop starts from headposition.
    {
        difference = absoluteValue(queue[j + 1] - queue[j]);
        seek = seek + difference;
        printf("Disk head moves from position %d to %d with Seek %d \n", queue[j], queue[j + 1],
               difference);
    }
    averageSeekTime = seek / (float)n;
    printf("Total Seek Time= %d\n", seek);
    printf("Average Seek Time= %f\n", averageSeekTime);
}
int absoluteValue(int x)
{
    if (x > 0)
    {
        return x;
    }
    else
    {
        return x * -1;
    }
}
/*
Output:
Enter the maximum range of Disk: 199
Enter the number of queue requests: 7
Enter the initial head position: 50
Enter the disk positions to be read (queue) : 82
170
43
140
24
16
190
Disk head moves from position 50 to 82 with Seek 32
Disk head moves from position 82 to 140 with Seek 58
Disk head moves from position 140 to 170 with Seek 30
Disk head moves from position 170 to 190 with Seek 20
Disk head moves from position 190 to 199 with Seek 9
Disk head moves from position 199 to 43 with Seek 156
Disk head moves from position 43 to 24 with Seek 19
Disk head moves from position 24 to 16 with Seek 8
Total Seek Time= 332
Average Seek Time= 47.428570
*/