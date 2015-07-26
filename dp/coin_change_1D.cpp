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
#define SETBIT(n,bit) ( (n) |= (1<<(bit)) )
#define CLEARBIT(n,bit) ( (n) &=  ~(1<<(bit)) )
#define CHECKBIT(n, bit)  ( (n) & (1 << (bit)) )
#define MAX 100000
using namespace std;

int main()
{
    long long n;
    while(cin>>n)
    {
        long long d[5]={50,25,10,5,1},m=5,i,j,coin[MAX]={0};
        coin[0]=1;
        for(i=0;i<m;i++)
            for(j=d[i];j<=n;j++)
                coin[j]+=coin[j-d[i]];
        cout<<coin[n]<<endl;
    }
    return 0;
}
