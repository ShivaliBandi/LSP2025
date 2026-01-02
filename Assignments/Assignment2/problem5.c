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
    int maxFileSize=0;
    char maxFileName[100];
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
        if(S_ISREG(sobj.st_mode) && maxFileSize<sobj.st_size)
        {
            maxFileSize=sobj.st_size;
            memset(maxFileName,'\0',100);
            strcpy(maxFileName,fileName);
            
        }
    

    }
    printf("Max file name - %s size %d\n",maxFileName,maxFileSize);
    closedir(dp);
    return 0;
}