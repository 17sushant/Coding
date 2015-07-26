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
#define MAX 50
using namespace std;
int main()
{
    int n,i,j,k,d=0,t=0,arr[MAX][MAX];
    cout<<"Enter n"<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            arr[i][j]=++t;
    }
    cout<<"Actual matrix is "<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<"Spirally/ helically printed matrix is"<<endl;
    while(d<(n/2))
    {
        for(k=d;k<n-d;k++)
            cout<<arr[d][k]<<" ";
        for(k=d+1;k<n-d;k++)
            cout<<arr[k][n-d-1]<<" ";
        for(k=n-d-2;k>=d;k--)
            cout<<arr[n-d-1][k]<<" ";
        for(k=n-d-2;k>d;k--)
            cout<<arr[k][d]<<" ";
        d++;
    }
    if(n%2!=0)
            cout<<arr[n/2][n/2]<<" ";
    return 0;
}
