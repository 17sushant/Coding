#include<stdio.h>
#include<ctype.h>
#include<iostream>
#include<math.h>
using namespace std;
long long NumOfSetBitsTillN(long long n)
{
    long long b,x,p,ans=n;
    for(b=0;n>0;((n=n>>1),b++));
    n=ans;
    if((n&(n+1))==0)
        return (b*pow(2,b-1));
    x=0;
    ans=0;
    while(b)
    {
        if((n>>(b-1))&1==1)
        {
            p=pow(2,b-1)-1;
            ans+=(x++)*(p+1)+NumOfSetBitsTillN(p);
        }
        b--;
    }
    ans+=x;
    return ans;
}
int main()
{
    long long n;
    cout<<"Find the total setbit till n"<<endl;
    cout<<"Enter n"<<endl;
    while(cin>>n)
    {
        cout<<"Total set bit till n is "<<NumOfSetBitsTillN(n)<<endl;
    }
    return 0;
}
