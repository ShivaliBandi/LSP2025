#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    DIR *dp;
    struct dirent *directoryPointer;
    struct stat statObj;
    char filePath[1024];
    int deletedCount=0;

    if(argc!=2)
    {
        printf("SYNTAX: %s <directory_path>\n",argv[0]);
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
            snprintf(filePath,sizeof(filePath),"%s/%s",argv[1],directoryPointer->d_name);
            if(lstat(filePath,&statObj)==-1) continue;

            if(S_ISREG(statObj.st_mode)&&statObj.st_size==0)
            {
                if(unlink(filePath)==0)
                {
                    printf("Deleted: %s\n",directoryPointer->d_name);
                    deletedCount++;
                }
                else
                {
                    perror("unlink failed");
                }
            }
        }
    }

    closedir(dp);
    printf("Total empty files deleted: %d\n",deletedCount);
    return 0;
}
