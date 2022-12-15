#include<stdio.h>

int main(){
    
    int n , ref_str[50] , no_frame , avail , page_fault = 0;
    int frame[10];
    printf("Enter the Number of Pages - ");
    scanf("%d" , &n);
    
    printf("Enter the Reference String - ");
    
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d" , &ref_str[i]);
    }
    
    printf("Enter the Number of Frames = ");
    scanf("%d" , &no_frame);
    
    for(int i = 0 ; i < no_frame ; i++)
        frame[i] = -1;
    
    int idx = 0;
    
    printf("\nref String  \t page Frames \tHit/Fault\n");
    
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d\t\t" , ref_str[i]);
        avail = 0;
        
        // Checking for Hit
        for(int k = 0 ; k < no_frame ; k++)
        {
            if(frame[k] == ref_str[i])
            {
                avail = 1;
                for(int j = 0 ; j < no_frame ; j++)
                {
                    printf("%d\t" , frame[j]);
                }
                
                printf("H");
            }
        }
        // Miss
        if(avail == 0)
        {
            frame[idx] = ref_str[i];
            idx = (idx+1) % no_frame;
            page_fault++;
            for(int k = 0 ; k < no_frame ; k++)
            {
                printf("%d\t" , frame[k]);
            }
            printf("F");
        }
        printf("\n");
    }
    
    printf("\nPage Fault is = %d " ,page_fault);
    printf("\nPage Fault ratio = %.2f\n",(float)page_fault/n);
   printf("\nPage Hit Ratio = %.2f\n",(float)(n- page_fault)/n);
    
    return 0;
    //4 7 6 1 7 6 1 2 7 2 2 2 6 1 3 4 6
}