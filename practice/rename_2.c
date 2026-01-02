#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
    int iRet=0;
    iRet=rename("./Hello.txt","./LSP.txt");
    if(iRet==0)
        printf("Yepiie rename success\n");
    else
        printf("%s \n",strerror(errno));
    return 0;
}