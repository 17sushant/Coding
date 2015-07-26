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
#define MAX 10000
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
        D={50,25,10,5,1};

        int dp[A+1];
        for(i=0;i<=A;i++)
            dp[i]=0;
        dp[0]=1;
        for(i=0;i<N;i++)
        {
            for(j=0;j<=A;j++)
            {
                if(D[i]<=j)
                    dp[j]+=dp[j-D[i]];
                else
                    dp[j]+=0;
            }
        }
        cout<<dp[A]<<endl;
    }
    return 0;
}
