#include<iostream>
#include<conio.h>
using namespace std;
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void segregate_0_1(int arr[],int n)
{
    int left=0,right=n-1;
    while(left<right)
    {
        while(arr[left]==0)
            left++;
        while(arr[right]==1)
            right--;
        if(left<right)
            swap(&arr[left],&arr[right]);
    }
}
int main()
{
    int arr[]={1,0,0,1,1,1,1,1,0,1,0,0,0,1,0,0,1,0,0,1,0,0},n=22;
    //int arr[]={0,0,0,0,0,0,0,0,0,0,0,0},n=12;
    segregate_0_1(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
