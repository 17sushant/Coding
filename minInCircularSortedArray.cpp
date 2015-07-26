#include<iostream>
#include<stdio.h>
#define MIN(a,b) ((a)>(b)?(b):(a))
using namespace std;
int minCircularSorted(int arr[],int st, int end)
{
    //cout<<"asd";
    //if(st>=end)
        //return 0;
    if(end-st+1==2)
        return(MIN(arr[st],arr[end]));
    else if(end-st+1==1)
        return(arr[st]);
    else
    {
        int mid=st + (end-st+1)/2 ;
        if(arr[st]>arr[mid])
            return(minCircularSorted(arr,st,mid));
        else
            return(minCircularSorted(arr,mid+1,end));
    }
}
int main()
{
    int arr[]={45,46,49,54,54,54,55,55,55,55,55,12,23,34,34,35,36,45};
    int n=18;
    cout<<minCircularSorted(arr,0,n-1);
    return 0;
}
