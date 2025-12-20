#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    struct stat sobj; //static object creation of stat srtucture 
    int iRet=0;
    iRet=stat("Demo.txt",&sobj);
    printf("INODE Number:%ld\n",sobj.st_ino);
    printf("Hard Link count:%ld\n",sobj.st_nlink);
    printf("Total size in bytes:%ld\n",sobj.st_size);
    printf("block size :%ld\n",sobj.st_blksize);
    

    return 0;
}