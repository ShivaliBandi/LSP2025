#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<dirent.h>
#include<sys/types.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        printf("ERROR:Invalid number of arguments\nSYNTAX -> problem3 <DIRECTORY NAME>\n");
        exit(-1);
    }
    DIR *dp=NULL;
    struct dirent *ptr=NULL;
    dp=opendir(argv[1]);
    if(dp==NULL)
        printf("%s\n",strerror(errno));
    else
        printf("DIRECTORY GETS OPENED \n");
   
    while(((ptr=readdir(dp))!=NULL)  )
    {
        struct stat sobj; //static object creation of stat srtucture 
        int iRet=0;
        char fileName[100];
        memset(fileName,'\0',100);
        sprintf(fileName,"%s/%s",argv[1],ptr->d_name); 
        iRet=lstat(fileName,&sobj);
        printf("%s -> ",ptr->d_name);
        if(S_ISBLK(sobj.st_mode))
            printf("BLOCK DEVICE\n");
        else if(S_ISCHR(sobj.st_mode))
            printf("CHARACTER  DEVICE\n");
        else if(S_ISDIR(sobj.st_mode))
            printf("DIRECTORY\n");
        else if(S_ISSOCK(sobj.st_mode))
            printf("SOCKET\n");
        else if(S_ISFIFO(sobj.st_mode))
            printf("FIFO\n");
        else if(S_ISLNK(sobj.st_mode))
            printf("SYMBOLIC LINK\n");
        else if(S_ISREG(sobj.st_mode))
            printf("REGULAR FILE\n");
   


    }
    closedir(dp);
    return 0;
}