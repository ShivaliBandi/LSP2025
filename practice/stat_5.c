#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
    struct stat sobj; //static object creation of stat srtucture 
    int iRet=0;
    iRet=stat(argv[1],&sobj);
    printf("INODE Number:%ld\n",sobj.st_ino);
    printf("Hard Link count:%ld\n",sobj.st_nlink);
    printf("Total size in bytes:%ld\n",sobj.st_size);
    printf("block size :%ld\n",sobj.st_blksize);
    


//we have used this to check the file type these are macros which gets  
//st_mode This field contains the file type and mode. https://man7.org/linux/man-pages/man7/inode.7.html
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
    else if(S_ISLNK(sobj.st_mode))
    {
         printf("SYMBOLIC LINK\n");
    }
    else if(S_ISREG(sobj.st_mode))
    {
         printf("REGULAR FILE\n");
    }
   
    return 0;
}