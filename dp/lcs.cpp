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

#define INF (1<<30)-1
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
    string X,Y;
    while(1)
    {
        long long m,n,i,j,lcs[MAX][MAX];
        cout<<"enter string"<<endl;
        cin>>X>>Y;
        m=X.length();
        n=Y.length();

        for(i=0;i<m;i++)
            lcs[i][0]=0;
        for(j=0;j<n;j++)
            lcs[0][j]=0;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(X[i-1]==Y[j-1])
                    lcs[i][j]=lcs[i-1][j-1]+1;
                else
                    lcs[i][j]=((lcs[i-1][j]>lcs[i][j-1])?lcs[i-1][j]:lcs[i][j-1]);
                cout<<lcs[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"Longest common subsequence length is "<<lcs[m][n]<<endl;
        //cout<<"And the LCS path is "<<
    }
    return 0;
}
