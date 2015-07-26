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
//int gcd(int a, int b){return (b? gcd(b,a%b):0);}
//int lcm(int a, int b) { return b*a/gcd(a,b); }
#define SETBIT(n,bit) ( (n) |= (1<<(bit)) )
#define CLEARBIT(n,bit) ( (n) &=  ~(1<<(bit)) )
#define CHECKBIT(n, bit)  ( (n) & (1 << (bit)) )
using namespace std;
int add(int a, int b)
{
    return a+b;
}
int sub(int a, int b)
{
    return a-b;
}
int mul(int a, int b)
{
    return a*b;
}
int mod(int a, int b)
{
    return a%b;
}
int main()
{
    int c,d,e;
    int (*fp1)(int,int);
    fp1=add;
    c=(*fp1)(4,6);

    int (*fp2)(int,int);
    fp2=&add;
    d=(*fp2)(14,16);

    int (*fp3)(int,int);
    fp3=&add;
    e=fp3(24,26);

    cout<<c<<" "<<d<<" "<<e<<endl;

    //array of function pointers...
    int (*fpa[4])(int,int);

    fpa[0]=add;
    fpa[1]=sub;
    fpa[2]=mul;
    fpa[3]=mod;

    int a,b;
    while(cin>>a>>b)
    {
        for(int i=0;i<4;i++)
            cout<<i<<" "<<(*fpa[i])(a,b)<<endl;;
    }
    return 0;
}
