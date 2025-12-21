#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
int main()
{
    
    int fd=0;
    fd=open("./Test/outputl.txt",O_RDONLY); //issue we cant open symbolic link file 
    if(fd ==-1)
    {
        printf("Unable to open a File %s\n",strerror(errno));
        return -1;

    }
    printf("FILE opened with fd : %d",fd);
    close(fd);

    return 0;
}