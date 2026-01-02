#include <fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
int main(int argc,char *argv[])
{
    if(argc!=2)
        perror("Invalid number of arguments\nSyntax-> problem1 <filename> \n");
    int fd=0;
    fd=open(argv[1],O_RDWR);
    if(fd==-1)
        perror(strerror(errno));
    else
        printf("File Opened successfully\n");
    close(fd);


    return 0;
}

/* 
Open File
• Accept file name from user and open it using open().
• Print: success message + returned file descriptor.
• Handle errors using perror().
*/