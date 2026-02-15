/* Develop a C program which demonstrates interprocess communication between a reader process 
and a writer process. Use mkfifo, open, read, write and close APIs in your program. */
//Writer (Producer) Process:
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <fcntl.h> 
#include <unistd.h> 
int main()  
{ 
const char *fifoName = "myfifo";  
mkfifo(fifoName, 0666); 
int fd = open(fifoName, O_WRONLY); 
if (fd == -1)  
{ 
perror("open"); 
exit(1); 
} 
const char *message = "Hello from the writer process!"; 
write(fd, message, strlen(message) + 1); 
close(fd); 
printf("Writer process has sent a message.\n"); 
return 0; 
}
//OUTPUT:   
//Reader (Consumer) Process:
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <fcntl.h> 
#include <unistd.h> 
int main()  
{ 
const char *fifoName = "myfifo";  
int fd = open(fifoName, O_RDONLY); 
if (fd == -1)  
{ 
perror("open"); 
exit(1); 
}
char buffer[100]; 
read(fd, buffer, sizeof(buffer)); 
close(fd); 
printf("Reader process received: %s\n", buffer); 
return 0; 
}
/*OUTPUT: 
Writer process has sent a message.
Reader process received: Hello from the writer process!
*/