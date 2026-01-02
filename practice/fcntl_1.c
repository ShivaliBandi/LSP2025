#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
int main()
{
    int iRet=0,fd=0;
    fd=open("SyncExample",O_WRONLY);
    if(fd==-1)
    {
        printf("ERROR: %s\n",strerror(errno));
        return -1;
    }

    //here we use fcntl function to get the flags and access mode of file that has opened
    iRet=fcntl(fd,F_GETFL);
    if(iRet==-1)
    {
        printf("FCNTL FAILED WITH : %s",strerror(errno));
    }
    int accessMode=iRet&O_ACCMODE;
    if(accessMode==O_WRONLY || accessMode==O_RDWR)
    {
        printf("file is opened in writeable mode\n");

    }
    else
    {
        printf("File is not opened in writable mode\n");
    }
    close(fd);
    return 0;

}