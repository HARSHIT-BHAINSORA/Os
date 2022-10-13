#include<stdio.h>
#include<unistd.h>

int main(){
    fork();
    printf("The pid is = " , getpid());
    return 0;
}