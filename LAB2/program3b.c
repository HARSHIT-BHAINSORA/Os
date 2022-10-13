// Orphan process

#include<stdio.h>
#include<unistd.h>

int main(){
    
    int p = fork();
    
    if(p == 0){
        
        sleep(5);
        printf("The child pid is %d\n" , getpid());
        printf("The child parent pid is %d\n" , getppid());
        exit(0);
    }
    else{
        printf("The parent process pid is %d\n" , getpid());
    }
    
}