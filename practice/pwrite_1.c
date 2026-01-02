#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
int main()
{
    int fd=0,iRet=0;
    off_t offset=0;
    char buffer[100]="PUNE";

    fd=open("./output.txt",O_WRONLY | O_APPEND);
   
    iRet=pwrite(fd,buffer,4,10);
    
   
    offset=lseek(fd,0,SEEK_CUR);
    printf("Current offset is %ld\n",offset);     
    return 0;
}
/*
rogrammerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/practice$ cat output.txt 
Marvellous Infosystem
programmerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/practice$ gcc pwrite_1.c 
programmerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/practice$ ./a.out
Current offset is 0
programmerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/practice$ ./a.out
Current offset is 0
programmerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/practice$ cat output.txt 
Marvellous Infosystem
PUNEPUNE

*/