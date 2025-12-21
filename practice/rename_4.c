#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    int iRet=0, fd=0;
    char cBuffer[50];
    memset(cBuffer,'\0',sizeof(cBuffer));

    fd=open("./process.txt",O_RDONLY);
    if(fd==-1)
    {
        printf("Unable to open File\n");
        return -1;
    }

    iRet=rename("./process.txt","./Test/LSP.txt");//rename in another directory it is same file check using stat command it just changes it name 
    //remaining all details remain same
    if(iRet==0)
        printf("Yepiie rename success\n");
    else
        printf("%s \n",strerror(errno));


    iRet=read(fd,cBuffer,50);
    if(iRet!=0)
        printf("Data from file is : %s",cBuffer);

    return 0;
}