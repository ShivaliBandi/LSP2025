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
    fd2=dup2(fd1,11);//using dup2 we can choose the fd by our own if thatr is availble it gives us, else fails 
    printf("fd2 %d\n",fd2);

    return 0;
}

/*

programmerinsane@programmerinsane-ROG-Strix-G531GV-G531GV:~/Documents/LSP2025/practice$ ./a.out
fd1: 3
fd2 11


*/