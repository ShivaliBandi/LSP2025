#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
int main()
{
    
    int iRet=0;
    char cBuffer[50];
    memset(cBuffer,'\0',sizeof(cBuffer));

    iRet=readlink("./outputl.txt",cBuffer,sizeof(cBuffer));
    if(iRet==-1)
        printf("ERROR: %s\n",strerror(errno));
    cBuffer[iRet]='\0';
    printf("READ LINK: %s\n",cBuffer);
    return 0;
}