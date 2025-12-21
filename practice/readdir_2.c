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
   
    while((ptr=readdir(dp))!=NULL)//readdir returns null if no file found mhnje end 
    {
        
        printf(" INODE number %ld \n",ptr->d_ino);
        printf("FILE NAME %s\n",ptr->d_name);
    }//we used while loop for displaying all files of that directory 
    
    return 0;
}