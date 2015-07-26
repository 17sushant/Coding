#include<iostream>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<utility>

#define INF (1<<31)-1
#define PI 3.1428571428571428571428571428571
#define MAXV(a,b) ( (a)>(b) ? (a) : (b) )
#define MINV(a,b) ( (a)<(b) ? (a) : (b) )
#define ABS(a) ( (a)>0 ? (a) : (-a) )
//int gcd(int a, int b){return (b? gcd(b,a%b):0);}
//int lcm(int a, int b) { return b*a/gcd(a,b); }
#define SETBIT(n,bit) ( (n) |= (1<<(bit)) )
#define CLEARBIT(n,bit) ( (n) &=  ~(1<<(bit)) )
#define CHECKBIT(n, bit)  ( (n) & (1 << (bit)) )
#define MAX 10
using namespace std;
void swap(int *p1, int *p2)
{
    int temp=*p1;
    *p1=*p2;
    *p2=temp;
}
void bubbleSort(int arr[])
{
    int i,j;
    for(i=0;i<MAX;i++)
        for(j=i+1;j<MAX;j++)
            if(arr[i]>arr[j])
                swap(&arr[i],&arr[j]);
}
int partition(int arr[],int start,int end)
{
    int key=arr[end];
    int i,j;
    i=start;
    j=start;
    while(j<=end-1)
    {
        if(arr[j]<key)
        {
            swap(&arr[i],&arr[j]);
            i++;
        }
        j++;
    }
    swap(&arr[i],&arr[end]);

    return i;
}
void quickSort(int arr[],int start,int end)
{
    if(start>end)
        return;
    int pi=partition(arr,start,end);
    quickSort(arr,start,pi-1);
    quickSort(arr,pi+1,end);
}
void merge(int arr[],int start, int mid, int end)
{
    if(end=start+1)
    {
        if(arr[start]<arr[end])
            swap(&arr[start],&arr[end]);
        return;
    }
    int i,j,k,temparr[end-start+1];
    i=start;
    j=mid+1;
    k=0;
    while(i<=mid && j<=end)
    {
        if(arr[i]<arr[j])
            temparr[k++]=arr[i++];
        else
            temparr[k++]=arr[j++];
    }
    if(i<=mid)
    {
        while(i<=mid)
            temparr[k++]=arr[i++];
    }
    else if(j<=end)
    {
        while(j<=end)
            temparr[k++]=arr[j++];
    }
    for(i=0,j=start;i<(end-start+1),j<=end;i++,j++)
    {
        arr[j]=temparr[i];
    }
}
void mergeSort(int arr[],int start,int end)
{
    cout<<"->"<<start<<" "<<" "<<end<<endl;
    if(start>=end)
        return;
    int mid=(end+start)/2;
    cout<<"inside mid "<<mid<<endl;
    //getchar();
    mergeSort(arr,start,mid);
    //cout<<"2"<<endl;
    mergeSort(arr,mid+1,end);
    //cout<<"3"<<endl;
    merge(arr,start,mid,end);
    //cout<<"4"<<endl;
}
void insertionSort(int arr[])
{

}

void selectionSort(int arr[])
{

}
int main()
{
    while(1)
    {
        int arr[MAX],i,ans;
        arr={4,5,1,2,8,6,9,0,7,3};
        //for(i=0;i<MAX;i++)
            //cin>>arr[i];
        cout<<"enter option"<<endl;
        cout<<"------------"<<endl<<endl;
        cout<<"1) Bubble Sort"<<endl;
        cout<<"2) Insertion Sort"<<endl;
        cout<<"3) Merge Sort"<<endl;
        cout<<"4) Quick Sort"<<endl;
        cout<<"5) Selection Sort"<<endl;
        cin>>ans;
        switch(ans)
        {
            case 1: bubbleSort(arr);
                    break;
            case 2: insertionSort(arr);
                    break;
            case 3: mergeSort(arr,0,MAX-1);
                    break;
            case 4: quickSort(arr,0,MAX-1);
                    break;
            case 5: selectionSort(arr);
                    break;

        }
        for(i=0;i<MAX;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}
