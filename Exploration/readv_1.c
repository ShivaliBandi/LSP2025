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

    char buff1[5],buff2[5];
    memset(buff1,'\0',sizeof(buff1));
    memset(buff2,'\0',sizeof(buff2));
    int fd=0,readcount,iovcnt;
    struct iovec iovc[2];
    iovc[0].iov_base=buff1;
    iovc[0].iov_len=5;
    iovc[1].iov_base=buff2;
    iovc[1].iov_len=5;
    iovcnt = sizeof(iovc) / sizeof(struct iovec);


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
rogrammerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/Exploration$ gcc readv_1.c 
programmerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/Exploration$ ./a.out
ReadCount =10 
Buffer1=hello shiv
Buffer2= shiv
10	 5 
this ole shows the output of buff1 as 10 read doesnt add \0 at the end so that why 
readv() reads raw bytes, not C strings, so it fills buff1 with 5 bytes (hello) and buff2 with the next 5 bytes 
( shiv) without adding a null terminator ('\0'). When you print buff1 using %s or call strlen(buff1), C expects a
  null-terminated string, so it keeps reading memory past buff1 into buff2 until it finds a '\0', which makes buff1 
  appear as "hello shiv" and strlen(buff1) return 10 instead of 5; this is undefined behavior. To fix it, either 
  allocate one extra byte and manually add '\0' after reading, 
or print using length-limited formats like %.5s
*/