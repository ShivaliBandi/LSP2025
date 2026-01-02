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
    if (strcmp(ptr->d_name,".")!=0 && strcmp(ptr->d_name,"..")!=0)
        printf("%s\n",ptr->d_name);
    }
    closedir(dp);
    return 0;
}