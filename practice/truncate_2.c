#include<stdio.h>
#include<unistd.h>
int main()
{
    int iRet=0;
    iRet=truncate("Demo.txt",30);

    if(iRet==0)
        printf("truncate successful\n");
    else
        printf("truncate unsucessful\n");
    return  0;
}