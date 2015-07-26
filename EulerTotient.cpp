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
#include<conio.h>

#define INF (1<<31)-1
#define PI 3.1428571428571428571428571428571
#define MAXV(a,b) ( (a)>(b) ? (a) : (b) )
#define MINV(aa,b) ( (a)<(b) ? (a) : (b) )
#define ABS(a) ( (a)>0 ? (a) : (-a) )
long long gcd(long long a, long long b) {return (b? gcd(b,a%b):a);}
//gcd(a,b) = gcd(b,a-b*(a/b))
//long long lcm(long long a, long long b) { return b*a/gcd(a,b); }
#define SETBIT(n,bit) ( (n) |= (1<<(bit)) )
#define CLEARBIT(n,bit) ( (n) &=  ~(1<<(bit)) )
#define CHECKBIT(n, bit)  ( (n) & (1 << (bit)) )
#define MAX 1000000
using namespace std;
long long prime[MAX],len;
bool seive[MAX];    // all are initially initialized to false seive[i]=false means i is a prime
long long seivePrime(long long n)
{
    long long p=3,j=0,i;
    prime[j++]=2;
    prime[j++]=3;
    while(p*p<=n)
    {
        i=p*p;
        while(i<=n)
        {
            seive[i]=true;
            i+=p;
        }
        p+=2;                   //avoiding those even p because that are not prime..
        while(seive[p]!=false)
        {
            p+=2;
        }
        prime[j++]=p;
    }
    len=j;
}

long long EulerTotient(long long n)
{
    long long i=0,phi=n;
    while(prime[i]<=sqrt(n))
    {
        if(n%prime[i]==0)
        {
            phi/=prime[i];
            phi*=prime[i]-1;
            while(n%prime[i]==0)
                n/=prime[i];
        }
        i++;
    }
    if(n>1)
    {
        phi/=n;
        phi*=n-1;
    }
    return phi;
}

int main()
{
    long long n;
    while(cin>>n)
    {
        seivePrime(n);
        cout<<EulerTotient(n)<<endl;
    }
    return 0;
}
