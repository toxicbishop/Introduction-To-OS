/*Develop a c program to implement the process system calls (fork( ), exec( ), wait( ), create 
process, terminate process)*/

#include <stdio.h>  
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
int main()  
{ 
pid_t child_pid; 
child_pid = fork(); 
if (child_pid < 0) { 
perror("Fork failed"); 
exit(1); 
} 
if (child_pid == 0)  
{ 
printf("Child process (PID: %d) is running...\n", getpid()); 
char *args[] = {"ls", "-l", NULL}; 
execvp ("ls", args); 
perror("Exec failed"); 
exit(1); 
}  
else  
{ 
printf("Parent process (PID: %d) is running...\n", getpid()); 
int status;
waitpid(child_pid, &status, 0); 
if (WIFEXITED(status))  
{ 
printf("Child process (PID: %d) has exited with status %d\n", child_pid, WEXITSTATUS(status)); 
}  
else if (WIFSIGNALED(status))  
{ 
printf("Child process (PID: %d) was terminated by signal %d\n", child_pid, WTERMSIG(status)); 
} 
printf("Parent process (PID: %d) is exiting...\n", getpid()); 
} 
return 0; 
}
/*Output
Parent process (PID: 12345) is running...
Child process (PID: 12346) is running...
Total 20

-rw-r--r-- 1 user group 1234 Jan 1 12:34 file1.txt
-rw-r--r-- 1 user group 5678 Jan 1 12:35 file2.txt
Child process (PID: 12346) has exited with status 0
Parent process (PID: 12345) is exiting...
*/