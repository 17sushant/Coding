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
#define MINI(a,b,c) ( MINV(MINV(a,b), c) )
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
    string A,B;
    int i,j,n,m,cd,ci,cr;
    //cout<<"enter the two string"<<endl;
    while(cin>>A>>B)
    {
        //cout<<"enter cost of insertion,deletion,replacement"<<endl;
        cin>>ci>>cd>>cr;
        cout<<ci<<" "<<cd<<" "<<cr<<" "<<endl;
        n=A.length();
        m=B.length();
        int dp[n+1][m+1];

        for(i=0;i<=n;i++)
            dp[i][0]=i*cd;
        for(i=0;i<=m;i++)
            dp[0][i]=i*ci;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                if(A[i-1]==B[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                    //cout<<"if dpi,j "<<dp[i][j]<<" "<<i<<" "<<j<<endl;
                }
                else
                {
                    dp[i][j]=MINV( (dp[i][j-1] + ci),MINV( (dp[i-1][j] + cd),(dp[i-1][j-1] + cr) ) );
                    //cout<<"else dpi,j "<<dp[i][j]<<" "<<i<<" "<<j<<endl;
                    //cout<<(dp[i-1][j] + cd)<<" "<<dp[i-1][j-1] + cr<<endl;
                }

            }
        /*for(i=0;i<=n;i++){
            for(j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
            }cout<<endl;}*/
        cout<<dp[n][m]<<endl;
    }
    return 0;
}
