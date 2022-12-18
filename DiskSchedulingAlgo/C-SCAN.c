#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void sort(int arr[] , int n)
{
    for(int i = 0 ; i < n-1 ; i++)
    {
        for(int j = 0 ; j < n-i-1 ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
}


int cscan(int request_queue[] , int seek_sequence[] , int current_head_pos , int n , int direction , int mx_track)
{
    printf("current_head_pos - %d\n" , current_head_pos); 
    int seekTime = 0;
    int left[n+3];
    int right[n+3];
    int l = 0 , r = 0;
    int idx = 0;
    
  
    left[l++] = 0;
    right[r++] = mx_track-1;

    
    for(int i = 0 ; i < n ; i++)
    {
        if(request_queue[i] < current_head_pos){
            left[l++] = request_queue[i];
        }
        else if(request_queue[i] > current_head_pos){
            right[r++] = request_queue[i];
        }
    }
    
    sort(left,l);
    sort(right,r);
    
    printf("Left\n");
    for(int i = 0 ; i < l ; i++)
        printf("%d " , left[i]);

    printf("\nright\n");
    for(int i = 0 ; i < r ; i++)
        printf("%d " , right[i]);        
        
    
    int run = 2;
    
    while(run--)
    {
        if(direction == 0)
        {
            for(int i = 0 ; i < l ; i++)
            {
                seek_sequence[idx++] = left[i];
                seekTime += abs(current_head_pos - left[i]);
                current_head_pos = left[i];
            }
            direction = 1;
        }
        else if(direction == 1)
        {
            for(int i = 0 ; i < r ; i++)
            {
                seek_sequence[idx++] = right[i];
                seekTime += abs(current_head_pos - right[i]);
                current_head_pos = right[i];
            }
            direction = 0;
        }
    
    }    
    
    printf("\nSeek Sequence: ");
        for(int i=0;i<idx;i++)
          printf("%d ",seek_sequence[i]);
        
        return seekTime;

}


int main(){
    
    int head , mx_track , n;
    int TotalSeekTime = 0 , seekTime = 0;
    int direction;
    
     printf("Enter the initial Position of RW head: ");
    scanf("%d",&head);
    
    printf("Enter the Maximum number of tracks = ");
    scanf("%d" , &mx_track);
    
    printf("Enter the number of Element in the requesting queue = ");
    scanf("%d" , &n);
    
    int seek_sequence[n+3];
    int request_queue[n]; 
    
    printf("Enter the Disk track Element = ");
    for(int i = 0; i < n; i++)
        scanf("%d" , &request_queue[i]);
    
    printf("Enter the Direction = ");
    scanf("%d",&direction);
   
    TotalSeekTime = cscan(request_queue , seek_sequence , head , n , direction , mx_track);
    
    printf("\nTotal No. of Head Movements = %d\n",TotalSeekTime);
    printf("\nAverage head movements = %.2f\n\n",(float)TotalSeekTime/n);
    return 0;
    //82 170 43 140 24 16 190
}
