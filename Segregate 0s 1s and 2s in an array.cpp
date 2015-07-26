#include<iostream>
#include<conio.h>
using namespace std;
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void segregate_0_1_2(int arr[],int n)
{
    int left=0,right=n-1,mid=0;
    while(mid<=right)
    {
        if(arr[mid]==0)
        {
            swap(&arr[left],&arr[mid]);
            left++;
            mid++;
        }
        else if(arr[mid]==1)
            mid++;
        else if(arr[mid]==2)
        {
            swap(&arr[right],&arr[mid]);
            right--;
        }
    }
}
int main()
{
    int arr[]={1,2,0,1,1,1,1,1,0,1,2,0,0,1,2,1,2,0,0,2,0,0,2,2,2,2,0,1,0,1,1,1,0},n=33;
    segregate_0_1_2(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
