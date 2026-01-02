#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
int main()
{
    
    int iRet=0;
    iRet=rmdir("./Data");
    if(iRet==-1)
        printf("%s\n",strerror(errno));
    else
        printf("DIRECTORY GETS DELETED \n");
    return 0;
}