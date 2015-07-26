#include<iostream>
using namespace std;
void maxji(int arr[],int n, int st, int end, int *max,int *x,int *y)
{
    if(end<=st || st>=n || end<0)
        return;
    if(arr[end]>arr[st])
        if(end-st>*max)
        {
            *max=end-st;*x=st;*y=end;
            return;
        }
    maxji(arr,n,st,end-1,max,x,y);
    maxji(arr,n,st+1,end,max,x,y);
}
int main()
{
    int arr[] = {6, 5, 4, 3, 2, 1},n=6,max=-1,x,y;
    maxji(arr,n,0,n-1,&max,&x,&y);
    cout<<max<<endl<<x<<endl<<y<<endl;
    return 0;
}
