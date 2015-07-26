#include<iostream>
using namespace std;
void find_duplicates(int arr[],int n)
{   int i,k;
    for(i=1;i<=n;i++)
        arr[arr[i]%(n+1)]+=n+1;
    for(i=1;i<=n;i++)
    {
        k=arr[i]/(n+1);
        if(k>1)
            cout<<i<<" is repeated "<<k<<" times"<<endl;
        else if(k==1)
            cout<<i<<" is not repeated"<<endl;
        else if(k==0)
            cout<<i<<" is not present in the array"<<endl;
    }
}
int main()
{
    int arr[]={0,6,5,7,3,4,2,5,9,7};// first 0 is for make index start from 1...
    find_duplicates(arr,9);
    return 0;
}
