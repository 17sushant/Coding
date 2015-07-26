#include<stdio.h>
#include<ctype.h>
#include<iostream>
using namespace std;
int next_largest_power_of_2(register unsigned int x)
{
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        return(x+1);
}
int msbZero(register unsigned int n)
{
    int old=n;
    n|=n>>1;
    n|=n>>2;
    n|=n>>4;
    n|=n>>8;
    n|=n>>16;
    //printf("%x\n",n);
    return(old ^ ((n+1)>>1) );
}
int reverse_bits(register unsigned int n)
{

    return();
}
int main()
{
    int i;
    while(cin>>i)
    {
        cout<<"The Next largest power of two is "<<next_largest_power_of_2(i)<<endl;;
        cout<<"The number after making most signicant 1 to zero is "<<msbZero(i)<<endl;
    }
    return 0;
}
