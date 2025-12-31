#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include<string.h>
#include<errno.h>

int main()
{

    char buff1[]=" Sheru ",buff2[]="Peru\n";
    int fd=0,writecount,iovcnt;
    struct iovec iovc[2];
    iovc[0].iov_base=buff1;
    iovc[0].iov_len=sizeof(buff1);
    iovc[1].iov_base=buff2;
    iovc[1].iov_len=sizeof(buff2);
    iovcnt = sizeof(iovc) / sizeof(struct iovec);
    fd=open("demo.txt",O_RDWR | O_APPEND);
    if(fd==-1)
        printf("%s\n",strerror(errno));
    writecount=writev(fd,iovc,iovcnt);
    printf("ReadCount =%d \n",writecount);
   
    close(fd);
    return 0;
}
/* 
programmerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/Exploration$ gcc writev_1.c 
programmerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/Exploration$ cat demo.txt 
hello shivali Sweety is a good girl sheru is naught boySheruPeruprogrammerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/Exploration$ cat demo.txt    ./a.out
ReadCount =12 
programmerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/Exploration$ cat demo.txt 
hello shivali Sweety is a good girl sheru is naught boySheruPeruSheruPeru

*/