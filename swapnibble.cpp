#include<iostream>
#include<stdio.h>
using namespace std;
char swapnibble(char ch)
{
    char t1,t2;
    t1=ch&0xf0;
    t2=ch&0x0f;

    t1=t1>>4;
    t2=t2<<4;
    return (t1|t2);
}
int main(void)
{
    char ch=0x34;
    //cout<<ch;
    //cout<<swapnibble(ch)<<endl;;
    printf("%x",swapnibble(ch));
    return 0;
}
