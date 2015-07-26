#include<iostream>
#include<stdio.h>
using namespace std;
bool subarray_sum(int arr[],int n,int s,int *x,int *y)
{
    int i,j;
    arr[0]=0;
    for(i=0;i<n;i++)
        arr[i]=arr[i]+arr[i-1];
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[j]-arr[i]==s)
            {
                *x=i;*y=j;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    while(1)
    {
        int i,arr[10],s,n=10,x,y;
        cout<<"enter array"<<endl;
        for(i=1;i<=n;i++)
            cin>>arr[i];
        cout<<"Enter the sum value"<<endl;
        cin>>s;
        if(subarray_sum(arr,n,s,&x,&y))
        {
            cout<<"Subarray from "<<(x)<<" to "<<(y)<<" sums up to "<<s<<endl;
        }
        else
        {
            cout<<"does not exist"<<endl;
        }
    }
    return 0;
}
