#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
int main()
{
    if(fork()==0)
    {
        printf("child process\n");
        execl("./commandexe","",NULL);//We ran execl from child process after fork what happens here is child procces copies the 
        //text data stack from parent so usually whenever we run fork child proces does this and when we ran execl from child it
        //flushes the text data and stack section
        //one more small point in output we see sequence in different way that because parent finished running and then immediatly
        //exits and give control to its parent that is the terminal and here in child it took time to finish 
    }
    else
    {
        printf("parent process\n");
    }
   
    return 0;

}   