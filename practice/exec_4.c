#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
int main()
{
    if(fork()==0)
    {
        printf("child process\n");
        execl("./commandexe","First","Demo","121","3.12",NULL);//we passed arguments here .when we run normal command line arguments
        //there argv[0] is the exe name right but here when we use execl system call argv[0] is the first argument that we pass
        //we tried passing int string float but remember it take all data types as string .
    }
    else
    {
        printf("parent process\n");
    }
   
    return 0;

}   