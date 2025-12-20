#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
int main()
{
    
    int iRet=0;
    iRet=mkdir("./Data",0777);
    if(iRet==-1)
        printf("%s\n",strerror(errno));
    else
        printf("DIRECTORY GET CREATED \n");
    return 0;
}