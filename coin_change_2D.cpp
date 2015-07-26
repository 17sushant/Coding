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
int main()
{
    int A,N,D[MAX],i,j;
    cout<<"enter amount A"<<endl;
    while(cin>>A)
    {
        //A=125;
        //cout<<"enter no. of denominations"<<endl;
        //cin>>N;
        N=5;
        //cout<<"enter the denomination array"<<endl;
        for(i=0;i<N;i++)
            //cin>>D[i];
        D={0,1,5,10,25,50};

        int dp[A+1][N+1];
        for(i=0;i<=A;i++)
            dp[i][0]=0;
        for(i=0;i<=N;i++)
            dp[0][i]=1;

        for(i=1;i<=A;i++)
            for(j=1;j<=N;j++)
            {
                if(i>=D[j])
                    dp[i][j]=dp[i][j-1] + dp[i-D[j]][j];
                else
                    dp[i][j]=dp[i][j-1];
            }

        /*for(i=0;i<=A;i++){
            for(j=0;j<=N;j++)
            {
                cout<<dp[i][j]<<" ";
            }cout<<endl;}*/
        cout<<endl<<dp[A][N]<<endl;
    }
    return 0;
}
