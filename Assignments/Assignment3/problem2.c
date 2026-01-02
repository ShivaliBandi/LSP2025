#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<limits.h>

int main(int argc,char *argv[])
{
    DIR *dp;
    struct dirent *directoryPointer;
    char fullPath[PATH_MAX];

    if(argc!=3)
    {
        printf("ERROR: Invalid arguments\nSYNTAX: %s <directory_path> <file_name>\n",argv[0]);
        return -1;
    }

    dp=opendir(argv[1]);
    if(dp==NULL)
    {
        perror("opendir failed");
        return -1;
    }

    int found=0;
    while((directoryPointer=readdir(dp))!=NULL)
    {
        if(strcmp(directoryPointer->d_name,".")!=0&&strcmp(directoryPointer->d_name,"..")!=0)
        {
            if(strcmp(directoryPointer->d_name,argv[2])==0)
            {
                snprintf(fullPath,sizeof(fullPath),"%s/%s",argv[1],argv[2]);
                char absPath[PATH_MAX];
                realpath(fullPath,absPath);
                printf("File found: %s\n",absPath);
                found=1;
                break;
            }
        }
    }

    found==0&&printf("File '%s' not found in directory '%s'\n",argv[2],argv[1]);
    closedir(dp);
    return 0;
}
