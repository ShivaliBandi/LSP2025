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

    char buff1[6],buff2[6];
    memset(buff1,'\0',sizeof(buff1));
    memset(buff2,'\0',sizeof(buff2));
    int fd=0,readcount,iovcnt;
    struct iovec iovc[2];
    iovc[0].iov_base=buff1;
    iovc[0].iov_len=5;
    iovc[1].iov_base=buff2;
    iovc[1].iov_len=5;
    iovcnt = sizeof(iovc) / sizeof(struct iovec);
    buff1[5]='\0';
    buff2[5]='\0';

    fd=open("demo.txt",O_RDWR);
    if(fd==-1)
    {
        printf("%s\n",strerror(errno));
    }
    readcount=readv(fd,iovc,iovcnt);
    printf("ReadCount =%d \n",readcount);
    printf("Buffer1=%s\nBuffer2=%s\n",buff1,buff2);
    printf("%ld\t %ld \n",strlen(buff1),strlen(buff2));
    close(fd);
    return 0;
}
/* 
programmerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/Exploration$ ./a.out
ReadCount =10 
Buffer1=hello
Buffer2= shiv
5	 5 
so the solution for htis is we need to read n-2 times as -1 because array index starts from zero and one more -1
 because we will at terminating \0 at end of the array

*/