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

#define INF ((1<<31)-1)
#define PI (3.1428571428571428571428571428571)
#define MAX2(a,b) ( (a)>(b) ? (a) : (b) )
#define MIN2(a,b) ( (a)<(b) ? (a) : (b) )
#define MIN3(a,b,c) ( MIN2( MIN2((a),(b)),(c) ) )
#define ABS(a) ( (a)>0 ? (a) : (-a) )
//long long gcd(long long a, long long b) {return (b? gcd(b,a%b):a);}
//gcd(a,b) = gcd(b,a-b*(a/b))
//long long lcm(long long a, long long b) { return b*a/gcd(a,b); }
#define SETBIT(n,bit) ( (n) |= (1<<(bit)) )
#define CLEARBIT(n,bit) ( (n) &=  ~(1<<(bit)) )
#define CHECKBIT(n, bit)  ( (n) & (1 << (bit)) )
using namespace std;
long long ugly_number(long long n)
{
    long long ugly[n+1],i2=1,i3=1,i5=1,j;
    ugly[1]=1;
    j=2;
    while(j<=n)
    {
        ugly[j]=MIN3(ugly[i2]*2,ugly[i3]*3,ugly[i5]*5);
        if(ugly[j]==ugly[i2]*2)
            i2++;
        if(ugly[j]==ugly[i3]*3)
            i3++;
        if(ugly[j]==ugly[i5]*5)
            i5++;
        //cout<<ugly[j]<<endl;
        j++;
    }
    return(ugly[1500]);
}
int main()
{
    cout<<"The 1500'th ugly number is "<<ugly_number(1500)<<"."<<endl;
    return 0;
}
