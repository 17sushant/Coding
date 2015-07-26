#include<iostream>
using namespace std;
int reverseBit(int n)
{
    unsigned int a=0;
    for(int i=0;i<sizeof(int)*8-1;i++)
    {
        a=(n&1) | a;
        a=a<<1;
        n=n>>1;
    }
    return a;
}
int main()
{
    cout<<(unsigned )reverseBit(1)<<endl;;
    return 0;
}
