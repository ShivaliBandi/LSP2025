#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    struct stat sobj; //static object creation of stat srtucture 
    int iRet=0;
    iRet=stat("Demo.txt",&sobj);
    if(iRet==0)
        printf("Stat works yeppie\n");
    else
        printf("Ohh no stat fails\n");
    return 0;
}