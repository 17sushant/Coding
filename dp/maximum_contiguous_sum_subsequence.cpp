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
    while(1)
    {
        long long n,arr[MAX],maxsum[MAX],st[MAX],end[MAX],i;
        cout<<"enter n"<<endl;
        cin>>n;
        cout<<"enter array"<<endl;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            if(i==0)
            {
                maxsum[0]=arr[0];
                st[0]=0;
                end[0]=0;
            }
            else
            {
                if(maxsum[i-1]+arr[i]>arr[i])
                {
                    maxsum[i]=maxsum[i-1]+arr[i];
                    st[i]=st[i-1];
                    end[i]=i;
                }
                else
                {
                    maxsum[i]=arr[i];

                    st[i]=i;
                    end[i]=i;
                }
            }
        }
        long long m=maxsum[0],s=st[0],e=end[0];
        for(i=0;i<n;i++)
        {
            if(maxsum[i]>m)
            {
                m=maxsum[i];
                s=st[i];
                e=end[i];
            }
        }
        cout<<"Maximum sum is "<<m<<" from "<<s<<" to "<<e<<endl;
    }
    return 0;
}
