#include<iostream>
#include<stdio.h>
#include<stack>
#define MAX 100000000
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
        while(p*p<=n && seive[p]!=false)
            p+=2;
        if(p*p<=n)
            prime[j++]=p;
    }

    while(p<=n)
    {
        if(seive[p]==false)
            prime[j++]=p;
        p+=2;                   //avoiding those even p because that are not prime..
        while(p<=n && seive[p]!=false)
            p+=2;
    }
    len=j;

}
int main()
{
    long long i;
    seivePrime(10000000);
    for(i=0;i<len;i++)
    {
        cout<<prime[i]<<endl;
    }
    cout<<endl<<len<<endl;
    return 0;
}
