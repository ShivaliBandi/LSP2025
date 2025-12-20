#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    int iRet=0;
    iRet=link("./demo.txt","./Test/demo.txt");
    if(iRet==0)
        printf("link works yeppie\n");
    else
        printf("Ohh no link fails\n");
    
    return 0;
}