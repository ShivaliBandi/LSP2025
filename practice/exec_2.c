#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
int main()
{
    if(fork()==0)
    {
        printf("child process\n");
        execl("./demo","",NULL);
    }
    else
    {
        printf("parent process\n");
    }
   
    return 0;

}   