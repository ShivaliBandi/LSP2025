#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>

#define BUFSIZE 1024

int moveFile(char *srcPath,char *destPath)
{
    int fdSrc,fdDest;
    ssize_t bytesRead,bytesWritten;
    char buffer[BUFSIZE];

    fdSrc=open(srcPath,O_RDONLY);
    if(fdSrc==-1)
    {
        perror("Source open failed");
        return -1;
    }

    fdDest=open(destPath,O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(fdDest==-1)
    {
        perror("Destination open failed");
        close(fdSrc);
        return -1;
    }

    while((bytesRead=read(fdSrc,buffer,BUFSIZE))>0)
    {
        bytesWritten=write(fdDest,buffer,bytesRead);
        if(bytesWritten!=bytesRead)
        {
            perror("write failed");
            close(fdSrc);
            close(fdDest);
            return -1;
        }
    }

    if(bytesRead==-1) perror("read failed");

    close(fdSrc);
    close(fdDest);

    if(unlink(srcPath)==-1) perror("unlink failed"); // delete source after copy
    return 0;
}

int main(int argc,char *argv[])
{
    DIR *dp;
    struct dirent *directoryPointer;
    struct stat statObj;
    char srcFile[1024],destFile[1024];
    int movedCount=0;

    if(argc!=3)
    {
        printf("SYNTAX: %s <source_dir> <dest_dir>\n",argv[0]);
        return -1;
    }

    dp=opendir(argv[1]);
    if(dp==NULL)
    {
        perror("opendir failed");
        return -1;
    }

    while((directoryPointer=readdir(dp))!=NULL)
    {
        if(strcmp(directoryPointer->d_name,".")!=0&&strcmp(directoryPointer->d_name,"..")!=0)
        {
            snprintf(srcFile,sizeof(srcFile),"%s/%s",argv[1],directoryPointer->d_name);
            if(lstat(srcFile,&statObj)==-1) continue;

            if(S_ISREG(statObj.st_mode))
            {
                snprintf(destFile,sizeof(destFile),"%s/%s",argv[2],directoryPointer->d_name);
                if(moveFile(srcFile,destFile)==0) movedCount++;
            }
        }
    }

    closedir(dp);
    printf("Total files moved: %d\n",movedCount);
    return 0;
}
