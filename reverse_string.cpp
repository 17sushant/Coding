#include<iostream>
#include<cstring>
#include<string.h>
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
#define MAX 10
using namespace std;

void rev(char * s,int start,int end)
{
    int i=0,lim;
    if((end-start)%2==0)
    {
        lim=(end-start)/2;
    }
    else
    {
        lim=(end-start)/2 + 1;
    }
    while(i<lim)
    {
        char ch=s[start+i];
        s[start+i]=s[end-i];
        s[end-i]=ch;
        i++;
    }
}
int main()
{
    char str[]="I am a good boyk";
    rev(str,0,strlen(str)-1);
    cout<<str<<endl;

    int i,x=0;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]==' ' || str[i]=='\0')
        {
            rev(str,x,i-1);
            x=i+1;
        }
    }
    cout<<str<<endl;
}
