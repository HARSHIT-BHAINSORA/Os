#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>


int findClosest(int current_head_pos , bool vis[] , int request_queue[] , int n)
{
    int mn = INT_MAX , mnIdx = -1;
    
    for(int i = 0 ;  i < n ; i++)
    {
        if(vis[i] == false && abs(current_head_pos - request_queue[i]) < mn)
        {
            mn = abs(current_head_pos - request_queue[i]);
            mnIdx = i;
        }
    }
    return mnIdx;
}

int sstf(int request_queue[] , bool vis[] , int seek_sequence[] , int n , int current_head_pos)
{
    int idx = 0 , tracks = 0 , head_movement = 0;
    
    while(tracks != n)
    {
        int minIdx = findClosest(current_head_pos , vis , request_queue , n);
        head_movement += abs(current_head_pos - request_queue[minIdx]);
        current_head_pos = request_queue[minIdx];
        seek_sequence[idx++] = request_queue[minIdx];
        vis[minIdx] = true;
        tracks++;
    }
    return head_movement;
}



int main()
{
    int current_head_pos , mx_track , n;
    int TotalSeekTime = 0 , seekTime = 0;
    
    printf("Enter the current head position = ");
    scanf("%d" , &current_head_pos);
    
    printf("Enter the Maximum number of tracks = ");
    scanf("%d" , &mx_track);
    
    printf("Enter the number of Element in the requesting queue = ");
    scanf("%d" , &n);
    
   
        
    int seek_sequence[n];
    int request_queue[n]; 
    bool vis[n];
    memset(vis , false , n*sizeof(bool));
    
    printf("Enter the Disk track Element = ");
    for(int i = 0; i < n; i++)
        scanf("%d" , &request_queue[i]);
    
    TotalSeekTime = sstf(request_queue, vis , seek_sequence , n , current_head_pos);
    
    printf("\nSeek Sequence: ");
    for(int i=0;i<n;i++)
     printf("%d ",seek_sequence[i]);

    printf("\nTotal No. of Head Movements = %d\n",TotalSeekTime);
    printf("\nAverage head movements = %.2f\n\n",(float)TotalSeekTime/n);
    return 0;
}