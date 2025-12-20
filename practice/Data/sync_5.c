#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
int main()
{
    
    int iRet=0,fd=0;
    char Arr[30];
    memset(Arr,'\0',sizeof(Arr));
    fd=open("SyncExample",O_WRONLY| O_CREAT | O_APPEND,0777);//IMP
    if(fd==-1)
    {
        printf("ERROR: %s\n",strerror(errno));
        return -1;
    }
  //  syncfs(fd);//OS SPECIFIC so its replacement is fsync
   // fsync(fd);
   fdatasync(fd);
    close(fd);
    return 0;
}