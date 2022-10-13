//Zombie process

#include<stdio.h>
#include<unistd.h>

int main(){
    
    int p = fork();
    
    if(p == 0){
        printf("The child pid is %d\n" , getpid());
        printf("The child parent pid is %d\n" , getppid());
    }
    else{
        sleep(5);
        printf("The parent process pid is %d\n" , getpid());
    }
    
}