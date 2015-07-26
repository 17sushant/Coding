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
using namespace std;
double sqrot(double num)
{
    double mod=1;
    double c=0;

    for(int d=0; d<50; c+=mod, d++)
    if(c*c>num)
    {
        c-=mod;
        mod/=10;
    }

    return c;
}
int main()
{
    cout<<sqrot(2)<<endl;;

    return 0;
}
