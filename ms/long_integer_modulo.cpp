#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
typedef unsigned long long llu;
llu powermodulo(llu n, llu i,llu k)
{
    llu powerm=1;
    for(llu j=0;j<i;j++)
    {
        powerm*=n;
        powerm%=k;
    }
    return powerm;
}
llu modulo(char *arr,llu l,llu k)
{
    llu b[1000],sum=0;
    for(llu i=0;i<l;i++)
    {
        b[i]=(arr[i]-48)%k* (powermodulo(10%k,l-i-1,k))%k;
        b[i]%=k;
        sum+=b[i];
    }
    return(sum%k);
}
int main()
{
    char arr[1000];
    llu k;
    while(cin>>arr)
    {
        cin>>k;
        llu l=strlen(arr);
        cout<<modulo(arr,l,k)<<endl;
    }
    return 0;

}
