#include<stdio.h>

int main()
{
    int n=5,m=3;
    

     int alloc[5][3] = {{ 0, 1, 0 },
                        { 2, 0, 0 }, 
                        { 3, 0, 2 }, 
                        { 2, 1, 1 }, 
                        { 0, 0, 2 } }; 
 
    int max[5][3] = { { 7, 5, 3 },
                      { 3, 2, 2 }, 
                      { 9, 0, 2 }, 
                      { 2, 2, 2 }, 
                      { 4, 3, 3 } }; 
 
    int avail[3] = { 3, 3, 2 };

    int need[5][3];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    int f[n],flag;
    for(int i=0;i<n;i++)
        f[i]=0;

    int complete=n;
    while(complete)
    {
        for(int i=0;i<n;i++)    
        {
            flag=0;
            if(f[i]!=1){
                for(int j=0;j<m;j++)
                {
                    if(avail[j]<need[i][j])
                    {
                        flag=1;
                        continue;
                    }
                }
                if(flag==0)
                {
                    f[i]=1;
                    complete--;
                    for(int j=0;j<m;j++)
                    {
                        avail[j]+=need[i][j];
                    }
                    printf("p%d \t",i);
                }
            }
        }
    }
}