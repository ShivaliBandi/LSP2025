#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    int iRet=0,fd=0;
    fd=open("Demo.txt",O_RDWR);
    iRet=ftruncate(fd,5);

    if(iRet==0)
        printf("truncate successful\n");
    else
        printf("truncate unsucessful\n");
    return  0;
}