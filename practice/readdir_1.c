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
    struct dirent *ptr=NULL;//we have created a ppinter of dirent structure which will hold the return value of readdir
    dp=opendir("./Data");
    if(dp==NULL)
        printf("%s\n",strerror(errno));
    else
        printf("DIRECTORY GETS OPENED \n");
    ptr = readdir(dp);
    printf(" INODE number %ld \n",ptr->d_ino);
    printf("FILE NAME %s\n",ptr->d_name);
    ptr = readdir(dp);
    printf(" INODE number %ld \n",ptr->d_ino);
    printf("FILE NAME %s\n",ptr->d_name);
    ptr = readdir(dp);
    printf(" INODE number %ld \n",ptr->d_ino);
    printf("FILE NAME %s\n",ptr->d_name);

    return 0;
}
//sequence of readdir is not fixed in all machine