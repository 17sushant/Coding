#include<iostream>
#include<stdio.h>
#define MAX 100
using namespace std;
void swap(int *p, int *q)
{
    int k=*p;
    *p=*q;
    *q=k;
}
void reverse(int arr[], int st, int end)
{
    int i=0;
    while(i<(end-st+1)/2)
    {
        swap(&arr[st+i],&arr[end-i]);
        i++;
    }
}
void right_rotate(int arr[], int n, int k)
{
    reverse(arr,0,n-1);
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
}
void left_rotate(int arr[], int n, int k)
{
    reverse(arr,0,n-1);
    reverse(arr,0,n-k-1);
    reverse(arr,n-k,n-1);
}
int main()
{
    int k,n,arr[MAX],arr2[MAX],ans,i;
    cout<<"enter no. of elements of array"<<endl;
    cin>>n;
    cout<<"enter elements"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        arr2[i]=arr[i];
    }
    cout<<"enter k"<<endl;
    cin>>k;

    while(1)
    {
        for(i=0;i<n;i++)
        {
            arr[i]=arr2[i];
        }
        cout<<"what do u want"<<endl;
        cout<<"1) Right rotate it "<<k<<" times"<<endl;
        cout<<"2) Left rotate it "<<k<<" times"<<endl;
        cin>>ans;
        if(ans==1)
            right_rotate(arr,n,k);

        else if(ans==2)
            left_rotate(arr,n,k);
        else
            break;
        for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}
