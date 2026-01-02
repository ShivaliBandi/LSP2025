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
    
    DIR *dp=NULL;
    dp=opendir("./Data");
    if(dp==NULL)
        printf("%s\n",strerror(errno));
    else
        printf("DIRECTORY GETS OPENED \n");
    
    return 0;
}