#include<stdio.h>
#include<stdlib.h>

int main(){
    
    int current_head_pos , mx_track , n;
    int request_queue[n] , TotalSeekTime = 0 , seekTime = 0;
    
    printf("Enter the current head position = ");
    scanf("%d" , &current_head_pos);
    
    printf("Enter the Maximum number of tracks = ");
    scanf("%d" , &mx_track);
    
    printf("Enter the number of Element in the requesting queue = ");
    scanf("%d" , &n);
    
    printf("Enter the Disk track Element = ");
    for(int i = 0; i < n; i++)
        scanf("%d" , &request_queue[i]);
    
    for(int i = 0; i < n ; i++)
    {
        seekTime = abs(current_head_pos - request_queue[i]);
        current_head_pos = request_queue[i];
        TotalSeekTime +=seekTime;
    }
    
    printf("Total Seek time is equal to:%d\n",TotalSeekTime);
    printf("Average Seek time:%.2f\n",(float)TotalSeekTime/n);    
}
