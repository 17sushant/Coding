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
#define SETBIT(n,bit) ( (n) |= (1<<(bit)) )
#define CLEARBIT(n,bit) ( (n) &=  ~(1<<(bit)) )
#define CHECKBIT(n, bit)  ( (n) & (1 << (bit)) )
#define MAX 100
using namespace std;
int main()
{
    long long n,i,j,k,arr[MAX],dp[MAX][MAX]={0},len,c=1,maxans;
    cout<<"enter length of array"<<endl;
    //cin>>n;
    len=10;
    cout<<"enter the array elements"<<endl;
    for(i=1;i<=len;i++)
        //cin>>arr[i];
    arr={0,1,4,6,3,9,8,6,2,3,1};
    n=((long long)sqrt(1+8*len) -1)/2;

    for(j=1;j<=n;j++)
    {
        for(i=n;i>(n-j);i--)
        {
            //dp[i][j]=arr[ ((j*(j+1))/2) - (i-(n-j)+1) +1+1];
            //dp[i][j]=arr[ c++ ];
            c=arr[ ((j*(j+1))/2) - (i-(n-j)+1) +1+1];
            if(j==1)
            {
                dp[i][j]=c;
                break;
            }
            if(i==n)
                dp[i][j]=MAXV(dp[i][j-1],dp[i-1][j-1]) + c;
            else if(i==(n-j+1))
                dp[i][j]=dp[i+1][j-1] +c;
            else if(i==(n-j+2))
                dp[i][j]=MAXV(dp[i][j-1],dp[i+1][j-1]) + c ;
            else
                dp[i][j]=MAXV(dp[i][j-1],MAXV(dp[i-1][j-1],dp[i+1][j-1])) +c;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(i==1)
            maxans=dp[i][n];
        else
        {
            if(maxans<dp[i][n])
                maxans=dp[i][n];
        }
    }
    //for(i=1;i<=n;i++){for(j=1;j<=n;j++){cout<<dp[i][j]<<" ";}cout<<endl;}
    cout<<maxans<<endl;
    return 0;
}
