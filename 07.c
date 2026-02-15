/* Develop a C program to simulate page replacement algorithms:
a) FIFO           b) LRU
*/
// a) FIFO
#include <stdlib.h>
#include <stdio.h>

int pagefault(int a[], int frame[], int n, int no)
{
    int i, j, avail, count = 0, k;
    /* initialize frame with value -1 */
    for (i = 0; i < no; i++)
    {
        frame[i] = -1;
    }
    j = 0;
    for (i = 0; i < n; i++)
    {
        avail = 0;
        for (k = 0; k < no; k++)
            /* if equal it means page number(reference) is available in frame */
            if (frame[k] == a[i])
                avail = 1;
        /* if avail=0 means page is not available in frame */
        if (avail == 0)
        {
            frame[j] = a[i];
            /* j will calculate the position at which the new page add */
            j = (j + 1) % no;
            count++; // variable count calculates the total page fault
        }
    }
    return count;
}
void main()
{
    int n, i, *a, *frame, no, fault;
    printf("\nENTER THE NUMBER OF PAGES:\n");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));
    printf("ENTER THE PAGE NUMBER :\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("ENTER THE NUMBER OF FRAMES :");
    scanf("%d", &no);
    frame = (int *)malloc(no * sizeof(int));
    fault = pagefault(a, frame, n, no);
    printf("Page Fault Is %d", fault);
}
/*Output:
ENTER THE NUMBER OF PAGES:
6
ENTER THE PAGE NUMBER :
2 2 3 4 6 4
ENTER THE NUMBER OF FRAMES :2
Page Fault Is 4
*/
// b) LRU

#include <stdio.h>
void main()
{
    int q[20], p[50], c = 0, c1, d, f, i, j, k = 0, n, r, t, b[20], c2[20];
    printf("Enter no of pages:");
    scanf("%d", &n);
    printf("Enter the reference string:");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);
    printf("Enter no of frames:");
    scanf("%d", &f);
    q[k] = p[k];
    printf("\n\t%d\n", q[k]);
    c++;
    k++;
    for (i = 1; i < n; i++)
    {
        c1 = 0;
        for (j = 0; j < f; j++)
        {
            if (p[i] != q[j])
                c1++;
        }
        if (c1 == f)
        {
            c++;
            if (k < f)
            {
                q[k] = p[i];
                k++;
                for (j = 0; j < k; j++)
                    printf("\t%d", q[j]);
                printf("\n");
            }
            else
            {
                for (r = 0; r < f; r++)
                {
                    c2[r] = 0;
                    for (j = i - 1; j < n; j--)
                    {
                        if (q[r] != p[j])
                            c2[r]++;
                        else
                            break;
                    }
                }
                for (r = 0; r < f; r++)
                    b[r] = c2[r];
                for (r = 0; r < f; r++)
                {
                    for (j = r; j < f; j++)
                    {
                        if (b[r] < b[j])
                        {
                            t = b[r];
                            b[r] = b[j];
                            b[j] = t;
                        }
                    }
                }
                for (r = 0; r < f; r++)
                {
                    if (c2[r] == b[0])
                        q[r] = p[i];
                    printf("\t%d", q[r]);
                }
                printf("\n");
            }
        }
    }
    printf("\nThe no of page faults is %d", c);
}
/*
Output:
Enter no of pages:10
Enter the reference string:5 6 6 7 83 4 9 5 2 4
Enter no of frames:3
5
5   6
5   6   7
5   6   7   83
5   6   7   83  4
9   6   7   83  4
9   5   7   83  4
9   5   2   83  4

The no of page faults is 8
*/