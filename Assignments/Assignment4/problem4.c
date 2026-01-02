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
    if(argc<3)
    {
        printf("ERROR:Invalid number of arguments\nSYNTAX -> problem4 <source file name> <destination file name>\n");
        exit(-1);

    }
    int fddestination=0;
    char buffer[100];
    memset(buffer,'\0',100);
    fddestination=open(argv[1],O_RDWR |O_CREAT |O_APPEND ,0777);
    if(fddestination==-1)
    {
        perror("ERROR destination File");
        return -1;
    }
    for(int i=2;i < argc;i++)
    {
        int readcount=0,writecount=0,fdsource=open(argv[i],O_RDONLY);
        if(fdsource==-1)
        {
            perror("ERROR Source File");
            return -1;
        } 
        while((readcount=read(fdsource,buffer,100))!=0)
        {
            
            writecount=write(fddestination,buffer,strlen(buffer));
            memset(buffer,'\0',100);
        }
        writecount=write(fddestination,"***********************************************\n",strlen("***********************************************\n"));
        close(fdsource);
    }
    close(fddestination);
    return 0;
}