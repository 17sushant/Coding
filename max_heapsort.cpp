#include<iostream>
#include<stdio.h>
#define MAX 100
#define PARENT(i) ( (i)>>1 )
#define LEFT(i) ( (i)<<1 )
#define RIGHT(i) ( ((i)<<1) + 1 )
#define MINV(a,b) ( ((a)<(b)) ? (a) : (b)  )
using namespace std;
int ar[MAX];
//and it is assumed that the left and right subtree are max heaps..
void max_heapify(int i,int n)
{
    int max_index;
    if(LEFT(i)<=n)
    {
        if(ar[i]>ar[LEFT(i)])
            max_index=i;
        else
            max_index=LEFT(i);
    }
    if(RIGHT(i)<=n)
    {
        if(ar[max_index]<ar[RIGHT(i)])
        {
            max_index=RIGHT(i);
        }

    }
    if(LEFT(i)>n && RIGHT(i)>n)
        max_index=i;
    if(max_index!=i)
    {
        int temp=ar[max_index];
        ar[max_index]=ar[i];
        ar[i]=temp;
        max_heapify(max_index,n);
    }
}
void build_max_heap(int n)
{
    int i;
    for(i=n/2;i>0;i--)
    {
        max_heapify(i,n);
    }
}
void heapsort(int n)
{
    int i;
    build_max_heap(n);
    for(i=n;i>1;i--)
    {
        int temp=ar[1];
        ar[1]=ar[i];
        ar[i]=temp;
        max_heapify(1,i-1);
    }

}
int main()
{
    int n,i,j;
    //cout<<"enter no. of elements"<<endl;
    //cin>>n;
    n=10;
    //cout<<"enter the array"<<endl;
    for(i=1;i<=n;i++)
        //cin>>ar[i];
    //ar={0,4,1,3,2,16,9,10,14,8,7};
    //heapsort(n);
    //build_max_heap(10);
    ar={0,16,4,10,14,7,9,3,2,8,1};
    max_heapify(2,10);
    for(i=1;i<=n;i++)
        cout<<ar[i]<<" ";
    cout<<endl;
    return 0;
}
