#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
int main()
{
    
    int iRet=0,fd=0;
    char cBuffer[50],Arr[30];
    memset(cBuffer,'\0',sizeof(cBuffer));
    memset(Arr,'\0',sizeof(Arr));

    iRet=readlink("./outputl.txt",cBuffer,sizeof(cBuffer));
    if(iRet==-1)
        printf("ERROR: %s\n",strerror(errno));
    cBuffer[iRet]='\0';
    printf("READ LINK: %s\n",cBuffer);
    fd=open(cBuffer,O_RDONLY);
    if(fd==-1)
    {
        printf("ERROR: %s\n",strerror(errno));
        return -1;
    }
    iRet=read(fd,Arr,10);
    printf("Data from orignal file  %s\n",Arr);
    close(fd);
    return 0;
}