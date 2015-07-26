#include<iostream>
using namespace std;
int binary_search(int arr[], int st, int end, int x)
{
    if(st==end)
    {
        //cout<<st<<endl;
        if(x==arr[st])
            return st;
        else
            return -11;
    }
    else if(st<end)
    {
        int mid=st+(end-st)/2;
        //cout<<st<<" "<<end<<" "<<mid<<endl;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]>x)
            return(binary_search(arr,st,mid-1,x));
        else
            return(binary_search(arr,mid+1,end,x));
            //return( (arr[mid]>x?binary_search(arr,st,mid-1,x):binary_search(arr,mid+1,end,x)) );
    }
    else
        return -11;
}
int main()
{
    int arr[]={1,4,-1,5,-8,5,-6,3,-10,15},indx[10],i,j,n=10,t=4,k=0;
    for(i=0;i<n;i++)
        if(arr[i]==t)
        {
            k=1;
            cout<<"Subarry that sums to "<<t<<" is a element at "<<i<<endl;
        }
    indx[0]=0;
    for(i=1;i<n;i++)
    {
        arr[i]=arr[i-1]+arr[i];
        indx[i]=i;
    }
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                int ind=indx[i];
                indx[i]=indx[j];
                indx[j]=ind;
            }
        }
    for(i=0;i<n;i++)
    {
        //binary search t+arr[i]
        j=binary_search(arr,i+1,n,t+arr[i]);
        if(j!=-11)
        {
            if(indx[i]+1<indx[j])
            {
                k=1;
                cout<<"Subarry that sums to "<<t<<" is from "<<indx[i]+1<<" to "<<indx[j]<<" "<<endl;
            }
        }
    }
    if(k==0)
        cout<<"no such subarray exist"<<endl;
    return 0;
}
