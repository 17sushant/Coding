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
#define M 100
using namespace std;
int main()
{
    long long n,dp[M],i,val[M],start[M],end[M],max,s,e;
    //cin>>n;
    n=10;
    for(i=1;i<=n;i++)
        //cin>>val[i];
    val={-213123,3,-4,5,-7,8,-6,21,-14,-9,-19};
    dp[0]=-1 * (INF-1000);
    max=dp[0];
    for(i=1;i<=n;i++)
    {
        if(dp[i-1]+val[i] >val[i])
        {
            dp[i]=dp[i-1]+val[i];
            start[i]=start[i-1];
            end[i]=end[i-1]+1;
        }
        else
        {
            dp[i]=val[i];
            start[i]=i;
            end[i]=i;
        }
        if(dp[i]>max)
        {
            max=dp[i];
            s=start[i];
            e=end[i];
        }
    }
    /*for(i=1;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }cout<<endl;

    for(i=1;i<=n;i++)
    {
        cout<<start[i]<<" ";
    }cout<<endl;

    for(i=1;i<=n;i++)
    {
        cout<<end[i]<<" ";
    }cout<<endl;
    */
    cout<<"maximum sum is "<<max<<" and it is from index "<<s<<" to "<<e<<endl;
    return 0;
}
