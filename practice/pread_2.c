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
    char buffer[100];

    fd=open("./output.txt",O_RDONLY);
    offset=lseek(fd,0,SEEK_SET);
    printf("Current offset is %ld\n",offset);

    iRet=read(fd,buffer,10);
    printf("\n");
    write(1,buffer,iRet);
    printf("\n");

    offset=lseek(fd,0,SEEK_CUR);
    printf("Current offset is %ld\n",offset);   
    return 0;
}