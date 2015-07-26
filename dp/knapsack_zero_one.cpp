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
#define MAX 100
using namespace std;

int main()
{
    long long i,j,mw,n,v[MAX],w[MAX],dp[MAX][MAX];
    cout<<"Enter no. of items and then its value and weights"<<endl;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i]>>w[i];
    cout<<"Enter maximum weights of knapsacl"<<endl;
    cin>>mw;
    for(i=0;i<=mw;i++)
        dp[0][mw]=0;
    for(i=0;i<=n;i++)
        dp[i][0]=0;
    for(i=1;i<=n;i++)
        for(j=0;j<=mw;j++)
        {
            if(j-w[i]>0)
                dp[i][j]=MAXV(dp[i-1][j],dp[i][j-w[i]]+v[i]);
            else
                dp[i][j]=dp[i-1][j];
        }
    cout<<dp[n][mw];
    return 0;
}
