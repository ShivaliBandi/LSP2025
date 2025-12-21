#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
int main()
{
    pid_t pid = 0;
    pid=fork();
    if(pid==0)
    {
        printf("CHILD SAYS: PID of current process %d  PID OF Parent %d   return value of fork %d\n",getpid(),getppid(),pid);
    }
    else
    {
        printf("PARENT SAYS: PID of current process %d  PID OF Parent %d   return value of fork %d\n",getpid(),getppid(),pid);

    }
    return 0;
    //here for this the output of parent process's pid would be terminal id to check run on same terminal " echo ?? "
}