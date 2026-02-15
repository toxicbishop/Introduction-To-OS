/*Develop a C program to simulate the following contiguous memory allocation techniques:
a) Worst fit b) Best fit c) First fit*/

// a) Worst fit
#include <stdio.h>
#define max 25
void main()
{
b) Best fit      
c) First fit 
int frag[max],b[max],f[max],i,j,nb,nf,temp,highest=0;
static int bf[max], ff[max];
printf("\n\tMemory Management Scheme - Worst Fit");
printf("\nEnter the number of blocks:");
scanf("%d", &nb);
printf("Enter the number of files:");
scanf("%d", &nf);
printf("\nEnter the size of the blocks:-\n");
for (i = 1; i <= nb; i++)
{
    printf("Block %d:", i);
    scanf("%d", &b[i]);
}
printf("Enter the size of the files :-\n");
for (i = 1; i <= nf; i++)
{
    printf("File %d:", i);
    scanf("%d", &f[i]);
}
for (i = 1; i <= nf; i++)
{
    for (j = 1; j <= nb; j++)
    {
        if (bf[j] != 1) // if bf[j] is not allocated
        {
            temp = b[j] - f[i];
            if (temp >= 0)
                if (highest < temp)
                {
                    ff[i] = j;
                    highest = temp;
                }
        }
    }
    frag[i] = highest;
    bf[ff[i]] = 1;
    highest = 0;
}
printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragment");
for (i = 1; i <= nf; i++)
    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
}
/*Output
Memory Management Scheme - Worst Fit
Enter the number of blocks: 5
Enter the number of files: 5

Enter the size of the blocks:-
Block 1:100
Block 2:500
Block 3:200
Block 4:300
Block 5:600
Enter the size of the files :-
File 1:50
File 2:150
File 3:250
File 4:350
File 5:450

File_no:	File_size :	Block_no:	Block_size:	Fragment
1		50		5		600		550
2		150		4		300		150
3		250		2		500		250
4		350		3		200		-150
5		450		1		100		-350
*/

// b) Best fit
#include <stdio.h>
#define MAX 25
void main()
{
    int frag[MAX], b[MAX], f[MAX], i, j, nb, nf, temp, lowest = 10000;
    static int bf[MAX], ff[MAX];
    printf("\n\tMemory Management Scheme - Best Fit");
    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);
    printf("Enter the number of files:");
    scanf("%d", &nf);
    printf("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }
    printf("Enter the size of the files :-\n");
    for (i = 1; i <= nf; i++)
    {
        printf("File %d:", i);
        scanf("%d", &f[i]);
    }
    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1) // if bf[j] is not allocated
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                    if (lowest > temp)
                    {
                        ff[i] = j;
                        lowest = temp;
                    }
            }
        }
        frag[i] = lowest;
        bf[ff[i]] = 1;
        lowest = 10000;
    }
    printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragment");
    for (i = 1; i <= nf; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
}
/*Output
Memory Management Scheme - Best Fit
Enter the number of blocks: 5
Enter the number of files: 5

Enter the size of the blocks:-
Block 1:100
Block 2:500
Block 3:200
Block 4:300
Block 5:600
Enter the size of the files :-
File 1:50
File 2:150
File 3:250
File 4:350
File 5:450

File_no:	File_size :	Block_no:	Block_size:	Fragment
1		50		1		100		50
2		150		3		200		50
3		250		2		500		250
4		350		4		300		-50
5		450		5		600		150
*/

// c) First fit
#include <stdio.h>
void main()
{
    int fragment[20], b[20], p[20], i, j, nb, np, temp, lowest = 9999;
    static int barray[20], parray[20];
    printf("\n\t\t\tMemory Management Scheme - Best Fit");
    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);
    printf("Enter the number of processes:");
    scanf("%d", &np);
    printf("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Block no.%d:", i);
        scanf("%d", &b[i]);
    }
    printf("\nEnter the size of the processes :-\n");
    for (i = 1; i <= np; i++)
    {
        printf("Process no.%d:", i);
        scanf("%d", &p[i]);
    }
    for (i = 1; i <= np; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (barray[j] != 1)
            {
                temp = b[j] - p[i];
                if (temp >= 0)
                    if (lowest > temp)
                    {
                        parray[i] = j;
                        lowest = temp;
                    }
            }
        }
        fragment[i] = lowest;
        barray[parray[i]] = 1;
        lowest = 10000;
    }
    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
    for (i = 1; i <= np && parray[i] != 0; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, p[i], parray[i], b[parray[i]], fragment[i]);
}
/* Output:
Enter the number of blocks: 3
Enter the number of files: 3

Enter the size of the blocks:-
Block 1:100
Block 2:500
Block 3:200

Enter the size of the files :-
File 1:50
File 2:150
File 3:250

File_no:	File_size :	Block_no:	Block_size:	Fragment
1		50		1		100		50
2		150		2		500		350
3		250		3		200		-50
5		450		5		600		150
*/

// c) First fit
#include <stdio.h>
void main()
{
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
    for (i = 0; i < 10; i++)
    {
        flags[i] = 0;
        allocation[i] = -1;
    }
    printf("Enter no. of blocks: ");
    scanf("%d", &bno);
    printf("\nEnter size of each block: ");
    for (i = 0; i < bno; i++)
        scanf("%d", &bsize[i]);
    printf("\nEnter no. of processes: ");
    scanf("%d", &pno);
    printf("\nEnter size of each process: ");
    for (i = 0; i < pno; i++)
        scanf("%d", &psize[i]);
    for (i = 0; i < pno; i++)
        for (j = 0; j < bno; j++)
            // allocation as per first fit
            if (flags[j] == 0 && bsize[j] >= psize[i])
            {
                allocation[j] = i;
                flags[j] = 1;
                break;
            }
    // display allocation details
    printf("\nBlock no.\tsize\t\tprocess no.\t\tsize");
    for (i = 0; i < bno; i++)
    {
        printf("\n%d\t\t%d\t\t", i + 1, bsize[i]);
        if (flags[i] == 1)
            printf("%d\t\t\t%d", allocation[i] + 1, psize[allocation[i]]);
        else
            printf("Not allocated");
    }
}
/*Output:
Enter no. of blocks: 3
Enter size of each block: 8 10 12
Enter no. of processes: 3
Enter size of each process: 56 14 12

Block no.	size		process no.		size
1		8		        Not allocated
2		10		        Not allocated
3		12		2		3          12
*/