#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<dirent.h>
#include<sys/types.h>
int main()
{
    
    char cBuffer[50];
    memset(cBuffer,'\0',sizeof(cBuffer));
    getcwd(cBuffer,sizeof(cBuffer));
    printf("current directory name: %s\n",cBuffer);
    chdir("./Data");
    memset(cBuffer,'\0',sizeof(cBuffer));
    getcwd(cBuffer,sizeof(cBuffer));
    printf("current directory name: %s\n",cBuffer);
    return 0;
}