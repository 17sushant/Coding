#include<iostream>
using namespace std;
long long bitCount(long long n)
{
    long long c=n - ((n>>1)&033333333333) - ((n>>2)&011111111111);
    c=(c + (c>>3)) & 030707070707;
    c=c%63;
    return c;
}
int main()
{
    long long n;
    while(cout<<"enter n"<<endl && cin>>n)
    {
        cout<<"Bits Count is "<<bitCount(n)<<endl;
    }
}
