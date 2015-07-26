#include<iostream>
#include<stdio.h>
using namespace std;
void printnumber(long long n)
{
    if(n==0)
        return;
    char r;
    r=(char)( n%10 + 48);
    printnumber(n/10);
    putchar(r);
}

int main()
{
    long long a=123456789;
    printnumber(a);
    return 0;
}
