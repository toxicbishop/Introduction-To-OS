/* Simulate following File Organization Techniques
a) Single Level Directory
b) Two Level Directory
*/

// a) Single Level Directory
#include <stdio.h>
#include <string.h>
void main()
{
    int nf = 0, i = 0, j = 0, ch;
// b) Two level directory 
char mname[10],fname[10][10],name[10];
printf("Enter the directory name:");
scanf("%s", mname);
printf("Enter the number of files:");
scanf("%d", &nf);
do
{
    printf("Enter file name to be created:");
    scanf("%s", name);
    for (i = 0; i < nf; i++)
    {
        if (!strcmp(name, fname[i]))
            break;
    }
    if (i == nf)
    {
        strcpy(fname[j++], name);
        nf++;
    }
    else
        printf("There is already %s\n", name);
    printf("Do you want to enter another file(yes - 1 or no - 0):");
    scanf("%d", &ch);
} while (ch == 1);
printf("Directory name is:%s\n", mname);
printf("Files names are:");
for (i = 0; i < j; i++)
    printf("\n%s", fname[i]);
}
/*Output:
Enter the directory name:
root
Enter the number of files:3
Enter file name to be created:file1
Do you want to enter another file(yes - 1 or no - 0):1
Enter file name to be created:file2
Do you want to enter another file(yes - 1 or no - 0):1
Enter file name to be created:file3
Do you want to enter another file(yes - 1 or no - 0):0
Directory name is:root
Files names are:
file1
file2
file3
*/

// b) Two Level Directory
#include <stdio.h>
#include <string.h>
void main()
{
    int i, j, n, ch, nf, k = 0;
    char mname[10][10], fname[10][10][10], name[10];
    printf("Enter the number of directories:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the directory name:");
        scanf("%s", mname[i]);
        printf("Enter the number of files in directory %s:", mname[i]);
        scanf("%d", &nf);
        for (j = 0; j < nf; j++)
        {
            printf("Enter file name to be created:");
            scanf("%s", name);
            for (k = 0; k < nf; k++)
            {
                if (!strcmp(name, fname[i][k]))
                    break;
            }
            if (k == nf)
            {
                strcpy(fname[i][j], name);
                nf++;
            }
            else
                printf("There is already %s\n", name);
        }
    }
    printf("Directory name\tFiles names\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t\t", mname[i]);
        for (j = 0; j < nf; j++)
            printf("%s\t", fname[i][j]);
        printf("\n");
    }
}
}
struct File *createFile(const char *name, const char *content)
{
    struct File *newFile = (struct File *)malloc(sizeof(struct File));
    if (newFile)
    {
        strcpy(newFile->name, name);
        strcpy(newFile->content, content);
    }
    return newFile;
}
void listContents(struct Directory *dir)
{
    printf("Contents of directory '%s':\n", dir->name);
    for (int i = 0; i < dir->num_files; i++)
    {
        printf("File: %s\n", dir->files[i].name);
    }
}
int main()
{
    root = createDirectory("root", NULL);
    struct Directory *currentDirectory = root;
    int choice;
    char name[50];
    do
    {
        printf("\nTwo-Level Directory Operations:\n");
        printf("1. Create Directory\n");
        printf("2. Create File\n");
        printf("3. List Contents\n");
        printf("4. Change Directory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter directory name: ");
            scanf("%s", name);
            struct Directory *newDir = createDirectory(name,
                                                       currentDirectory);
            if (newDir)
            {
                printf("Directory '%s' created.\n", name);
            }
            else
            {
                printf("Error creating directory.\n");
            }
            break;
        case 2:
            printf("Enter file name: ");
            scanf("%s", name);
            struct File *newFile = createFile(name, "Sample content.");
            if (newFile)
            {
                if (currentDirectory->num_files < 100)
                {
                    currentDirectory->files[currentDirectory->num_files] =
                        *newFile;
                    currentDirectory->num_files++;
                    printf("File '%s' created.\n", name);
                }
                else
                {
                    printf("Directory is full. Cannot create more files.\n");
                }
            }
            else
            {
                printf("Error creating file.\n");
            }
            break;
        case 3:
            listContents(currentDirectory);
            break;
        case 4:
            printf("Enter directory name: ");
            scanf("%s", name);
            struct Directory *newDirectory = NULL;
            for (int i = 0; i < currentDirectory->num_files; i++)
            {
                if (strcmp(currentDirectory->files[i].name, name) == 0)
                {
                    newDirectory = currentDirectory;
                    break;
                }
            }
            if (newDirectory)
            {
                currentDirectory = newDirectory;
                printf("Changed to directory: %s\n", name);
            }
            else
            {
                printf("Directory not found.\n");
            }
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}
/*Output:
Two-Level Directory Operations:
1. Create Directory
2. Create File
3. List Contents
4. Change Directory
5. Exit
Enter your choice: 1
Enter directory name: programs
Directory 'programs' created.

Two-Level Directory Operations:
1. Create Directory
2. Create File
3. List Contents
4. Change Directory
5. Exit
Enter your choice: 2
Enter file name: Notes
File 'Notes' created.

Two-Level Directory Operations:
1. Create Directory
2. Create File
3. List Contents
4. Change Directory
5. Exit
Enter your choice: 3
Contents of directory 'root':
File: Notes

Two-Level Directory Operations:
1. Create Directory
2. Create File
3. List Contents
4. Change Directory
5. Exit
Enter your choice: 4
Enter directory name: programs
Changed to directory: programs

Two-Level Directory Operations:
1. Create Directory
2. Create File
3. List Contents
4. Change Directory
5. Exit
Enter your choice: 2
Enter file name: C_Programs
File 'C_Programs' created.

Two-Level Directory Operations:
1. Create Directory
2. Create File
3. List Contents
4. Change Directory
5. Exit
Enter your choice: 3
Contents of directory 'programs':
File: C_Programs

Two-Level Directory Operations:
1. Create Directory
2. Create File
3. List Contents
4. Change Directory
5. Exit
Enter your choice: 5
Exiting...
*/