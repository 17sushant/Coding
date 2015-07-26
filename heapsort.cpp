#include<iostream>
#include<stdio.h>
#define MAX 100
#define PARENT(i) ( (i)>>1 )
#define LEFT(i) ( (i)<<1 )
#define RIGHT(i) ( ((i)<<1) + 1 )
#define MINV(a,b) ( ((a)<(b)) ? (a) : (b)  )
using namespace std;
int ar[MAX];
//and it is assumed that the left and right subtree are min heaps..
void min_heapify(int i,int n)
{
    int min_index;
    if(LEFT(i)<=n)
    {
        if(ar[i]<ar[LEFT(i)])
            min_index=i;
        else
            min_index=LEFT(i);
    }
    if(RIGHT(i)<=n)
    {
        if(ar[min_index]>ar[RIGHT(i)])
            min_index=RIGHT(i);
    }
    if(LEFT(i)>n && RIGHT(i)>n)
        min_index=i;

    if(min_index!=i)
    {
        int temp=ar[min_index];
        ar[min_index]=ar[i];
        ar[i]=temp;

        min_heapify(min_index,n);
    }
}
void build_min_heap(int n)
{
    int i;
    for(i=n/2;i>0;i--)
    {
        min_heapify(i,n);
    }
}
void heapsort(int n)
{
    int i;
    build_min_heap(n);
    for(i=n;i>1;i--)
    {
        int temp=ar[1];
        ar[1]=ar[i];
        ar[i]=temp;
        min_heapify(1,i-1);
    }
}
int main()
{
    int n,i,j;
    //cout<<"enter no. of elements"<<endl;
    //cin>>n;
    n=15;
    //cout<<"enter the array"<<endl;
    for(i=1;i<=n;i++)
        //cin>>ar[i];
    ar={0,4,1,3,2,16,9,10,14,8,7,3,12,23,12,2};
    heapsort(n);
    for(i=1;i<=n;i++)
        cout<<ar[i]<<" ";
    cout<<endl;
    return 0;
}
