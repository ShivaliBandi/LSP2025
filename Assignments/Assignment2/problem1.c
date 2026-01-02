#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>
int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        printf("ERROR:Invalid number of arguments\nSYNTAX -> problem1 <filename>\n");
        exit(-1);
    }
    int fd=0,readcount=0,totalReadCount=0;
    char buffer[10];
    memset(buffer,'\0',10);
    fd=open(argv[1],O_RDONLY);
    if(fd==-1)
    {
        perror("ERROR");
        return -1;
    }
    while((readcount=read(fd,buffer,10))!=0)
    {
        totalReadCount+=readcount;
        
        printf("%s",buffer);
        memset(buffer,'\0',10);//this line is imp because when the count is less then 10 and if i dont flush this end la if 3 letter
        //read kela tr display kartana 4th to 10th idex madhe data ahe so print hotay
    }
    printf("\n\nTOTAL READ COUNT: %d",totalReadCount);
    close(fd);
    return 0;
}