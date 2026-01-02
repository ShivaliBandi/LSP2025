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
   int fd=0,readcount=0;
   char buffer[atoi(argv[2])];
   memset(buffer,'\0',atoi(argv[2]));
   fd=open(argv[1],O_RDONLY);
    if(fd==-1)
        perror(strerror(errno));
    else
    {
        printf("File Opened successfully FD=%d\n",fd);
        readcount=read(fd,buffer,atoi(argv[2]));
        if(readcount!=-1)
        {
            printf("Data is : %s\n",buffer);
        }
        else
            perror("READ FAILED");
        
    }
        
    close(fd);
    return 0;
}