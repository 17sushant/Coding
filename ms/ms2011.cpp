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
using namespace std;
void swap(char *p, char *q)
{
    if(p==q)
        return;
    char temp=*p;
    *p=*q;
    *q=temp;
}
int main()
{
    char arr[100]="12345678abcdefgh";
    int x,y,z,len;
    //while(cin>>arr)
    while(1)
    {
        len=strlen(arr);
        x=1;
        y=len/2;
        z=y;
        while(x<len)
        {
            //if(x==z/2)
                //z+=(len-z)/2;
            if(x%2!=0)
            {
                swap(&arr[x],&arr[y]);
                x++;
                y++;
            }
            else
            {
                swap(&arr[x],&arr[z]);
                x++;
            }
            cout<<arr<<" "<<"x="<<x<<" "<<"y="<<y<<endl;
        }
        //cout<<arr<<endl;
        getchar();
    }
    return 0;
}
