#include<iostream>
#include<stdio.h>
#include<stack>
#define MAX 1000
#define INF ((1<<31) - 3)
using namespace std;
int main()
{
    long long i,j,mj[MAX],n,arr[MAX];
    //cin>>n;
    n=11;
    //for(i=1;i<=n;i++)
        //cin>>arr[i];
    arr={-1212, 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    mj[n]=0;
    for(i=n-1;i>0;i--)
    {
        if (arr[i] == 0)
            mj[i] = INF;
        if(n-i<=arr[i])
            mj[i]=1;
        else
        {
            mj[i]=INF;
            for(j=1;j<=arr[i];j++)
                if(mj[i+j]<mj[i])
                {
                    if(mj[i+j]==INF)
                        mj[i]=INF;
                    else
                        mj[i]=mj[i+j]+1;
                }

        }
    }
    cout<<mj[1]<<endl;
    return 0;
}
