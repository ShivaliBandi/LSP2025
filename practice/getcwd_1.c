#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
int main()
{
   printf("current directory name: %s\n",getcwd());//Error
    return 0;
}