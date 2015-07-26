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
#define SETBIT(n,bit) ( (n) |= (1<<(bit)) )
#define CLEARBIT(n,bit) ( (n) &=  ~(1<<(bit)) )
#define CHECKBIT(n, bit)  ( (n) & (1 << (bit)) )
#define MAX 100
using namespace std;
void sort(long long *p,long long m)
{
    long long i,j;
    for(i=0;i<m;i++)
    {
        for(j=i+1;j<m;j++)
        {
            if(*(p+j)<*(p+i))
            {
                long long temp=*(p+i);
                *(p+i)=*(p+j);
                *(p+j)=temp;
            }
        }
    }
}
int main()
{
    while(1)
    {
        long long d[MAX],m,i,n,j,coin[MAX][MAX];
        cout<<"enter the no. of denominatios"<<endl;
        cin>>m;
        for(i=0;i<m;i++)
            cin>>d[i];
        sort(d,m);
        cout<<"enter amount of money to be changed"<<endl;
        cin>>n;
        for(i=0;i<m;i++)
            coin[0][i]=1;

        for(i=1;i<=n;i++)
        {
            for(j=0;j<m;j++)
            {

                if(i-d[j]<0 && j-1>=0)
                    coin[i][j]=0 + coin[i][j-1];
                else if(i-d[j]>0 && j-1<0)
                    coin[i][j]=coin[i-d[j]][j] + 0;
                else if(i-d[j]<0 && j-1<0)
                    coin[i][j]= 0 + 0;
                else if(i-d[j]>=1 && j-1<0)
                    coin[i][j]=0;
                else
                    coin[i][j]=coin[i-d[j]][j] + coin[i][j-1];
                //cout<<i<<" "<<j<<" "<<coin[i][j]<<" "<<endl;;
            }
            //cout<<endl;
        }
        cout<<coin[n][m-1]<<endl;;
    }
    return 0;
}
