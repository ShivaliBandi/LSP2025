#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    int iRet=0;
    iRet=unlink("outputt");

    return 0;
}