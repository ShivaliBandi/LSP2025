#include <fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        printf("ERROR:Invalid number of arguments\nSYNTAX -> problem3 <filename> mode(read/write/execute)\n");
        exit(-1);
    }
    if(strcmp(argv[2],"read")==0)
    {
        if(access(argv[1],R_OK)!=0)
            perror("Doesnt have READ Access permission");

    }
    else if(strcmp(argv[2],"write")==0)
    {
        if(access(argv[1],W_OK)!=0)
            perror("Doesnt have WRITE Access permission");

    }
    else if(strcmp(argv[2],"execute")==0)
    {
        if(access(argv[1],X_OK)!=0)
            perror("Doesnt have EXECUTE Access permission");

    }
    else
        printf("ERROR:invalid mode passed \nplease pass read or write or execute modes only)\n");

    return 0;
}