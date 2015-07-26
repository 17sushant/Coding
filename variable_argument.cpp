#include<iostream>
#include<cstring>
#include<math.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<utility>
#include<cstdarg>

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

void fun(int a,int b,...)
{
    va_list vl;
    va_start(vl,b); // a int last argument of all arguments passed n before ,... in the fucntion
    for(int i=0;i<a;i++)
    {
        cout<<va_arg(vl,int)<<endl;
    }
    va_end(vl);
    cout<<"end is end"<<endl;
}
int main()
{
    fun(3,3,4,5,6);
    fun(5,2,10,11,12,13,14);
    return 0;
}
