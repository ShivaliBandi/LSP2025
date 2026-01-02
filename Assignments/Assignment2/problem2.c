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
        printf("ERROR:Invalid number of arguments\nSYNTAX -> problem5 <filename> <number of bytes to read>\n");
        exit(-1);
    }
    int fd=0,writecount=0;
    fd=open(argv[1],O_RDWR | O_APPEND);
    if(fd==-1)
    {
        perror("ERROR");
        return -1;
    }
    writecount=write(fd,argv[2],strlen(argv[2]));
    if(writecount==-1)
    {
        perror("ERROR");
    }
    printf("write COUNT: %d",writecount);
    close(fd);
    return 0;
}


/* 

if we can to write a code where we dont know how many strings are there use forloop and iterate the loop for writing 
*/