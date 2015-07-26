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
#define MAX 100
using namespace std;

int main()
{
    long long n,i,arr[MAX],lis[MAX],j,max,pred[MAX];
    cout<<"enter the number of elements"<<endl;
    cin>>n;
    cout<<"enter elements"<<endl;
    for(i=1;i<=n;i++)
        cin>>arr[i];
    lis[0]=0;
    for(i=1;i<=n;i++)
    {
        max=0;
        for(j=1;j<=i-1;j++)
        {
            if(arr[i]>arr[j])
            {
                max=((max>lis[j])?max:lis[j]);
                pred[i]=j;
            }
        }
        lis[i]=max+1;
    }
    max=0;
    for(i=1;i<=n;i++)
        max=(lis[i]>max)?lis[i]:max;
    cout<<max<<endl;
    return 0;
}
