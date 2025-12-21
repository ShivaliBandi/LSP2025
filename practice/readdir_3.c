#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<dirent.h>
#include<sys/types.h>
int main()
{
    
    DIR *dp=NULL;
    struct dirent *ptr=NULL;
    dp=opendir("./Data");
    if(dp==NULL)
        printf("%s\n",strerror(errno));
    else
        printf("DIRECTORY GETS OPENED \n");
   
    while((ptr=readdir(dp))!=NULL)
    {
        
       /*
       fd=open(ptr->d_name,O_RDONLY);
       
       suggestion to try opening file here and do some operation for better understanding
       */
    }
    closedir(dp);
    return 0;
}