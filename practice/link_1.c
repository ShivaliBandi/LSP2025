#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    int iRet=0;
    iRet=link("output.txt","newOutput.txt");//hard link we create had link in same directory
    if(iRet==0)
        printf("link works yeppie\n");
    else
        printf("Ohh no link fails\n");
    
    return 0;
}