#include<iostream>
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
void print_mcm(long long array[][MAX],long long a,long long b)
{
    long long k=array[a][b];
    if(a==b)
    {
        cout<<"A"<<a;
        return;
    }
    cout<<"(";
    print_mcm(array,a,k);
    cout<<")";
    cout<<"*";
    cout<<"(";
    print_mcm(array,k+1,b);
    cout<<")";
}
int main()
{
    long long n,i,p[MAX],dp[MAX][MAX],s[MAX][MAX],j,k,l,x;
    //cout<<"enter number of matrices"<<endl;
    //cin>>n;
    n=6;
    //cout<<"enter the matrices order array"<<endl;
    for(i=0;i<=n;i++)
        //cin>>p[i];
    p={30,35,15,5,10,20,25};
    for(i=1;i<=n;i++)
        dp[i][i]=0;

    for(l=1;l<n;l++)
        for(i=1;i<=n-l;i++)
        {
            j=i+l;
            dp[i][j]=INF;
            for(k=i;k<j;k++)
            {
                x=dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                if(x<dp[i][j])
                {
                    s[i][j]=k;
                    dp[i][j]=x;
                }
            }
        }
        /*for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){cout<<s[i][j]<<" ";}cout<<endl;}*/
    cout<<"Minimum cost ="<<dp[1][n]<<endl;
    cout<<"The parathesizes minmum product is "<<endl;
    print_mcm(s,1,n);
    return 0;
}
