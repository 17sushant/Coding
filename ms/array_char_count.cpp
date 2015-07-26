#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char arr[1000];
    while(cin>>arr)
    {
        int i=0,j=1,c=1,len=strlen(arr),digitcount=1,tens=10,k;
        while(j<=len)
        {
            if(arr[i]!=arr[j])
            {
                if(c>1)
                {
                    while(c>0)
                    {
                        k=digitcount--;
                        arr[i+1+--k]=(c%10)+48;
                        c=c/10;
                    }

                }
                c=1;
                digitcount=1;
                tens=10;
                i=j;
                j++;
            }
            else
            {
                c++;
                if(c>=tens)
                {
                    tens*=10;
                    digitcount++;
                }
                arr[j]='*';
                j++;
            }
        }
        for(i=0;i<len;i++)
        {
            if(arr[i]!='*')
                cout<<arr[i];
        }
        cout<<endl;
    }
    return 0;
}
