#include<iostream>
#include<stdio.h>
#define MAXV 100
#define INF (1<<31 - 2)
using namespace std;
int main()
{
    long long m,n,sum[MAXV][MAXV],arr[MAXV][MAXV],maxsum=-1*INF,i,j,k,xa,xb,ya,yb;
    long long x1,x2,x1temp,y1,y2,ms,dp,tt;
    while(cin>>m>>n)
    {
        for(i=1;i<=m;i++)
        {
            sum[i][0]=0;
            for(j=1;j<=n;j++)
            {
                cin>>arr[i][j];
                sum[i][j]=sum[i][j-1]+arr[i][j];
            }
        }
        y1=1;y2=1;
        for(i=1;i<=n;i++)
            for(j=0;j<=i-1;j++)
            {
                dp=ms=sum[1][i]-sum[1][j];
                x1=x2=x1temp=1;
                for(k=2;k<=n;k++)
                {
                    tt=(sum[k][i]-sum[k][j]);
                    if(tt+dp>tt)
                    {
                        dp=dp+tt;
                        if(dp>ms)
                        {
                            ms=dp;
                            x2=k;
                            x1=x1temp;

                        }
                    }
                    else
                    {
                        dp=tt;
                        x1temp=k;
                        if(dp>ms)
                        {
                            ms=dp;
                            x1=x2=k;
                        }
                    }
                }
                if(ms>maxsum)
                {
                    maxsum=ms;
                    xa=x1;xb=x2;
                    ya=j+1;yb=i;
                }
            }
        cout<<"MAximum sum is "<<maxsum<<endl;
        cout<<"SubArray is "<<endl;
        cout<<xa<<" "<<ya<<" "<<xb<<" "<<yb<<endl;
        for(i=xa;i<=xb;i++)
        {
            for(j=ya;j<=yb;j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
