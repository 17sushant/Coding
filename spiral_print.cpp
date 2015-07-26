#include<iostream>
#include<stdio.h>
using namespace std;
void spiral_print(int arr[][10],int m, int n)
{
    int i=0,k=m,j,l=n,loop,sum=0,v;

    if(m==1)
    {
        for(v=0;v<n;v++)
            cout<<arr[0][v]<<" ";
        return;
    }
    else if(n==1)
    {
        for(v=0;v<m;v++)
            cout<<arr[v][0]<<" ";
        return;
    }

    loop=(m>n?n:m)/2;
    while(loop--)
    {
        for(j=(n-l);j<=l-1;j++) {cout<<arr[i][j]<<" ";sum+=arr[i][j];}
        j--;
        for(i=(m-k+1);i<=k-1;i++) {cout<<arr[i][j]<<" ";sum+=arr[i][j];}
        i--;
        for(j=(l-2);j>=(n-l);j--) {cout<<arr[i][j]<<" ";sum+=arr[i][j];}
        j++;
        for(i=(k-2);i>=(m-k+1);i--) {cout<<arr[i][j]<<" ";sum+=arr[i][j];}
        i++;
        k--;
        l--;
    }
    if(m%2!=0 && n%2!=0)
    {
        if(m>n)
        {
            j++;
            for(v=i+1;v<=k-1;v++) {cout<<arr[v][j]<<" ";sum+=arr[v][j];}
        }
        else
        {
            for(v=j+1;v<=l-1;v++) {cout<<arr[i][v]<<" ";sum+=arr[i][v];}
        }
    }

    cout<<endl<<"Sum = "<<sum<<endl;
}
int main()
{
    int arr[10][10];
    int i,j,m,n,k;
    while(cin>>m>>n)
    {
        k=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                arr[i][j]=++k;
        }
        cout<<"Actual array is "<<endl;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                printf("%3d",arr[i][j]);
            cout<<endl;
        }
        cout<<"Spiral Printing of above array "<<endl;
        spiral_print(arr,m,n);
        cout<<endl<<"Correct "<<(m*n*m*n + m*n)/2<<endl;;
    }
    return 0;
}
