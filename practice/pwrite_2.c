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

    fd=open("./output.txt",O_WRONLY );
   //pwrite means doing lseek and write so if we do both in our normal code this wont run atomically in case due to some reason 
   //process2 interrupts our process1 and  process2 start runing and we just did lseek and we weere about to write so now
   //p2 is refering same file for example then if that process wants to write in same file at the end of file but because we did lseek
   //it will write at wrong place and in this way this is problem for p1 and p2 so if we use pwrite then lseek and write happens
   //atomically then another process can work and it doesnt affect on our offset too it doesnt change offset
    iRet=pwrite(fd,buffer,4,10);
    
   
    offset=lseek(fd,0,SEEK_CUR);
    printf("Current offset is %ld\n",offset);   
   
   
    return 0;
}

/*
output:
programmerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/practice$ cat output.txt 
Marvellous Infosystems
programmerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/practice$ gcc pwrite_2.c 
programmerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/practice$ ./a.out
Current offset is 0
programmerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/practice$ cat output.txt 
MarvellousPUNEosystems
programmerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/practice$ ^C
programmerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/practice$ 



*/