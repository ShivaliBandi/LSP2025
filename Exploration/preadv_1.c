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
    readcount=preadv(fd,iovc,iovcnt,SEEK_SET+7);
    printf("ReadCount =%d \n",readcount);
    printf("Buffer1=%s\nBuffer2=%s\n",buff1,buff2);
    printf("%ld\t %ld \n",strlen(buff1),strlen(buff2));
    close(fd);
    return 0;
}
/* 

*/