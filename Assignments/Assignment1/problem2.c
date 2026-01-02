#include <fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    if(argc<2)
        perror("Invalid number of arguments\nSyntax-> problem1 <filename>  <modes>\nmodes are  r - read\nw - write\n wr/rw - read and write\na - append");   
    int fd=0,flags=0;
    for(int i=2;i<argc;i++)
    {
        if (strcmp(argv[i], "wr") == 0 || strcmp(argv[i], "rw") == 0)
        {
            flags |= O_RDWR;
        }
        else if (strcmp(argv[i], "r") == 0)
        {
            flags |= O_RDONLY;
        }
        else if (strcmp(argv[i], "w") == 0)
        {
            flags |= O_WRONLY;
        }
        else if(strcmp(argv[i], "a") == 0)
        {
            flags |= O_APPEND;
        }
        else
        {
            printf("ERROR: Give appropriate mode\n r - read\nw - write\n wr/rw - read and write\na - append\n");
            exit(-1);
        }
        
    }
    fd=open(argv[1],flags);
    if(fd==-1)
        perror(strerror(errno));
    else
        printf("File Opened successfully FD=%d,FLAGS=%d\n",fd,flags);
    close(fd);


    return 0;
}

/* 
Open File in Given Mode
• Accept file name and mode (R, W, RW, A) from user.
• Convert mode to flags (O_RDONLY, O_WRONLY, O_RDWR, O_APPEND | O_CREAT).
• Open file accordingly and display fd.
*/