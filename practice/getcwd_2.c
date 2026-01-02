#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
int main()
{
    char cBuffer[50];
    memset(cBuffer,'\0',sizeof(cBuffer));
    getcwd(cBuffer,sizeof(cBuffer));
    printf("current directory name: %s\n",cBuffer);
    return 0;
}