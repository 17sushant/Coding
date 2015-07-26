#include<iostream>
#define INF ((1<<31)-1)
using namespace std;
int maxDifference(int arr[],int n)
{
    int i,minSoFar,maxdiff=-1*INF;
    minSoFar=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]-minSoFar>maxdiff)
            maxdiff=arr[i]-minSoFar;
        if(arr[i]<minSoFar)
            minSoFar=arr[i];
    }
    return(maxdiff);
}
int main()
{
    int arr[]={7, 9, 5, 6, 3, 2},n=6;
    cout<<maxDifference(arr,n)<<endl;
    return 0;
}
