#include<stdio.h>
#include<unistd.h>

int main(){
    int p[2];
    int returnstatus;
    char writemsg[2][25] = {"Operating" , "System"};
    char readmsg[25];
    
    returnstatus = pipe(p);
    
    if(returnstatus < 0)
    {
        printf("Pipe is not Created...");
    }
    else
    {
        printf("Writing to pipe msg = %s\n" , writemsg[1]);
        write(p[1], writemsg[1] , sizeof(writemsg[1]));
        read(p[0] , readmsg , sizeof(readmsg));
        
        printf("Reading from pipe - msg = %s", readmsg);
        return 0;
    }
    
}
