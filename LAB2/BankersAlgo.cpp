#include<bits/stdc++.h>
using namespace std;


struct Process{
    int A , B , C; // resources
};


int main()
{
    int n , A , B , C;
    cout<<"Enter the Number of Process - ";
    cin>>n;

    struct Process allocated[n];
    struct Process require[n];
    struct Process Need[n];
    int isExecute[n] = {0};
    int ans[n];

                
    for(int i = 0 ; i < n ; i++)
    {
        cout<<"Enter the Allocated and Required Resources of P"<< i << " - ";
        cin>>allocated[i].A >> allocated[i].B >> allocated[i].C;
        cin>>require[i].A >> require[i].B >> require[i].C;

        Need[i].A = require[i].A - allocated[i].A;
        Need[i].B = require[i].B - allocated[i].B;
        Need[i].C = require[i].C - allocated[i].C;  
    }

    cout<<"Enter the Avaliable Resources = ";
    cin>>A >> B >> C;

    int idx = 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(isExecute[j] == 0)
            {
                if(Need[j].A <= A && Need[j].B <= B && Need[j].C <= C)
                {
                    A += allocated[j].A;
                    B += allocated[j].B;
                    C += allocated[j].C;

                    ans[idx] = j;
                    idx++;
                    isExecute[j] = 1;
                    break;
                } 

            }
        }
    }


    for(int i = 0 ; i < n ; i++)
    {
        if(isExecute[i] == 0)
        {
            cout<<"No Safe Sequence is Possible";
            return 0;
        }
    }

    cout<<"The Safe Sequence is - ";
    for(int i = 0 ; i < n-1 ; i++)
    {
        cout <<"P"<<ans[i] << "->";
    }
    cout << "P"<<ans[n-1];
    return 0;
}    