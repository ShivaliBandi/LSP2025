#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>
int main(int argc,char *argv[])
{


    struct stat sobj;
    if(argc!=2)
    {
        printf("ERROR:Invalid number of arguments\nSYNTAX -> problem4 <filename> \n");
        exit(-1);
    }
    stat(argv[1],&sobj);
    printf("Total Size:%ld\n",sobj.st_size);
    printf("Block Size: %ld\n",sobj.st_blksize);
    printf("INODE:%ld\n",sobj.st_ino);
    printf("Hard Link count:%ld\n",sobj.st_nlink);
    printf("User ID of owner:%d\n",sobj.st_uid);
    printf("Group ID of owner:%d\n",sobj.st_gid);
    printf("FILE TYPE IS : %d \n",sobj.st_mode);
    if(S_ISBLK(sobj.st_mode))
    {
        printf("BLOCK DEVICE\n");
    }
    else if(S_ISCHR(sobj.st_mode))
    {
         printf("CHARACTER  DEVICE\n");
    }
    else if(S_ISDIR(sobj.st_mode))
    {
         printf("DIRECTORY\n");
    }
    else if(S_ISSOCK(sobj.st_mode))
    {
         printf("SOCKET\n");
    }
    else if(S_ISFIFO(sobj.st_mode))
    {
         printf("FIFO\n");
    }
    else if(S_ISREG(sobj.st_mode))
    {
         printf("REGULAR FILE\n");
    }
    else if(S_ISLNK(sobj.st_mode))
    {
         printf("SYMBOLIC LINK\n");
    }
    printf("LAST ACCESS/MODIFIED FILE:%s\n",ctime(&sobj.st_atime));
//ctime() is a standard C library function that converts the time_t value into a formatted string for printing. 
//time_t Used for time in seconds.  According to POSIX, it is an integer type.
    return 0;
}