#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    int iRet=0;
    iRet=symlink("output.txt","newOutput.txt");
    if(iRet==0)
        printf("symlink works yeppie\n");
    else
        printf("Ohh no symlink fails\n");
    
    return 0;
}