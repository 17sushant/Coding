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
    while(1)
    {
        string a,b;
        long long ci,cr,cd,i,j,m,n,edit[MAX][MAX];
        cout<<"enter the two string"<<endl;
        cin>>a>>b;
        cout<<"enter the cost of insertion, cost of deleteion and cost of replacement"<<endl;
        cin>>ci>>cd>>cr;
        m=a.length();
        n=b.length();
        for(i=0;i<=m;i++)
            edit[i][0]=i*cd;
        for(j=0;j<=n;j++)
            edit[0][j]=j*ci;
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
            {
                if(a[i-1]==b[j-1])
                    edit[i][j]=edit[i-1][j-1];
                else
                {
                    edit[i][j]=MINV(edit[i-1][j-1]+cr, MINV(edit[i-1][j]+cd, edit[i][j-1]+ci) );
                }
            }
        for(i=0;i<=n;i++){
            for(j=0;j<=m;j++){
            cout<<edit[i][j]<<" ";
            }cout<<endl;}
        cout<<edit[m][n]<<endl;
    }
    return 0;
}

