#include<iostream>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>

#define INF (1<<30)
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
class edge
{
    public:
    long long first,second,value;

    edge()
    {
        first=-1;
        second=-1;
        value=-1;
    }
    edge(long long f, long long s,long long val)
    {
        first=f;
        second=s;
        value=val;
    }
    void make_edge(long long f, long long s,long long val)
    {
        first=f;
        second=s;
        value=val;
    }
};
void mst_prim(long long adj[MAX][MAX],long long n)
{

}
int main()
{
    long long n,adj[MAX][MAX];
    long long u[MAX],i,j;
    cout<<"Enter the no. of nodes"<<endl;
    cin>>n;
    cout<<"Enter the adjacency matrix"<<endl;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          cin>>adj[i][j];
    mst_prim(adj,n);
    return 0;
}
