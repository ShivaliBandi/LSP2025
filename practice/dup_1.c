#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
int main()
{
    int fd1=0,fd2=0;
    fd1=open("output.txt",O_RDWR);
    printf("fd1: %d\n",fd1);
    fd2=dup(fd1);
    printf("fd2 %d\n",fd2);

    return 0;
}

/*
using dup system call we can duplicate the fd ,all we can say if its a topan name and reference like cpp ,because it uses same file table 
programmerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/practice$ ./a.out
fd1: 3
fd2 4


*/