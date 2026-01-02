#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>
int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        printf("ERROR:Invalid number of arguments\nSYNTAX -> problem1 <source file name> <destination file name>\n");
        exit(-1);
    }
    int fdsource=0,fddestination=0,readcount=0,writecount=0;
    char buffer[10];
    memset(buffer,'\0',10);

    fdsource=open(argv[1],O_RDONLY);
    fddestination=open(argv[2],O_RDWR | O_CREAT | O_APPEND,0777);
    if(fdsource==-1)
    {
        perror("ERROR Source File");
        return -1;
    }
    if(fddestination==-1)
    {
        perror("ERROR destination File");
        return -1;
    }
    while((readcount=read(fdsource,buffer,10))!=0)
    {
        
        writecount=write(fddestination,buffer,strlen(buffer));
        memset(buffer,'\0',10);
    }

    close(fdsource);
    close(fddestination);
    return 0;
}