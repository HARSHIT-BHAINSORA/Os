#include<stdio.h>



int FindLRU(int time[] , int n)
{
    int pos = 0;
    int mn = time[0];
    for(int i = 1 ; i < n ; i++)
    {
        if(mn > time[i])
        {
            mn = time[i];
            pos = i;
        }
    }
    
    return pos;
}

int main(){
    
    int n , ref_str[50] , no_frame , page_fault = 0 , t = 0;
    int frame[10] , flag1 , flag2 , time[10] ;
    
    printf("Enter the Number of Pages = ");
    scanf("%d", &n);
    
    printf("Enter the Reference String = ");
    
    for(int i = 0 ; i < n ; i++)
        scanf("%d" , &ref_str[i]);
    
    printf("Enter the Number of Frames = ");
    scanf("%d" , &no_frame);
    
    for(int i = 0 ; i < no_frame ; i++)
        frame[i] = -1;
    
    
    
    for(int i = 0 ; i < n ; i++)
    {
        flag1 = flag2 = 0;
        
       // Checking for Hit
       
       for(int j = 0 ; j < no_frame ; j++)
       {
           if(frame[j] == ref_str[i])
            {
                t++;
                time[j] = t;
                flag1 = flag2 = 1;
                break;
            }
       }
        // Initial Miss 
        if(flag1 == 0)
        {
            for(int j = 0 ; j < no_frame ; j++)
            {
                if(frame[j] == -1)
                {
                    t++;
                    page_fault++;
                    frame[j] = ref_str[i];
                    time[j] = t;
                    flag2 = 1;
                    break;
                }
            }
        }
        
        if(flag2 == 0)
        {
            int pos = FindLRU(time , no_frame);
            t++;
            page_fault++;
            frame[pos] = ref_str[i];
            time[pos] = t;
        }
        printf("\n");
        
        for(int j = 0 ; j < no_frame ; j++)
            printf("%d\t" , frame[j]);
    }
    
    printf("\n\n Total Page Faults = %d" , page_fault);
    return 0;
}
