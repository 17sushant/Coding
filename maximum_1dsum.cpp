#include<iostream>
using namespace std;
#define MAX 10000
int main()
{
    long long n,arr[MAX],dp,maxsum,x1,x2,x1temp,i;
    while(cin>>n && n!=0)
    {
        cin>>arr[0];
        dp=arr[0];
        maxsum=arr[0];
        x1=x2=x1temp=0;
        for(i=1;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]+dp>arr[i])
            {
                dp=arr[i]+dp;
                if(maxsum<dp)
                {
                    maxsum=dp;
                    x2=i;
                    x1=x1temp;
                }
            }
            else
            {
                dp=arr[i];
                x1temp=i;
                if(maxsum<dp)
                {
                    maxsum=dp;
                    x1=x2=i;
                }
            }
        }
        cout<<"Maximum continous sum is "<<maxsum<<endl;
        cout<<x1<<" "<<x2<<endl;
    }
    return 0;
}
