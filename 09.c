/*) Develop a C program to simulate the Linked file allocation strategies*/
#include<stdio.h> 
struct file 
{ 
char fname[10]; 
int start,size,block[10]; 
}f[10]; 
void main() 
{ 
int i,j,n; 
printf("Enter no. of files:"); 
scanf("%d",&n); 
for(i=0;i<n;i++) 
{ 
printf("Enter file name:"); 
scanf("%s",&f[i].fname); 
printf("Enter starting block:"); 
scanf("%d",&f[i].start); 
f[i].block[0]=f[i].start; 
printf("Enter no.of blocks:"); 
scanf("%d",&f[i].size); 
printf("Enter block numbers:"); 
for(j=1;j<=f[i].size;j++) 
{ 
scanf("%d",&f[i].block[j]);
} 
} 
printf("File\tstart\tsize\tblock\n");  
for(i=0;i<n;i++) 
{ 
printf("%s\t%d\t%d\t",f[i].fname,f[i].start,f[i].size); 
for(j=1;j<=f[i].size-1;j++) 
printf("%d--->",f[i].block[j]); 
printf("%d",f[i].block[j]); 
printf("\n"); 
} 
}
/*
Output:
Enter no. of files:3
Enter file name:file1
Enter starting block:10
Enter no.of blocks:3
Enter block numbers:
12
15
18
Enter file name:file2
Enter starting block:20
Enter no.of blocks:2
Enter block numbers:
22
25
Enter file name:file3
Enter starting block:30
Enter no.of blocks:4
Enter block numbers:
32
35
38
40
File    start   size    block
file1   10      3       12--->15--->18
file2   20      2       22--->25
file3   30      4       32--->35--->38--->40
*/