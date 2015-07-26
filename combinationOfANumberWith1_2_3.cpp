#include<iostream>
#include<cstring>
#include<sstream>
#define MAX 1000
using namespace std;
void PrintCombinationOfNumberWithOnly1_2_3(string str,long long n, long long k)
{
    long long i;
    if(n<0)
        return;
    if(n==0)
    {
        cout<<str<<endl;;
        return;
    }
    for(i=1;i<=k;i++)
    {
        stringstream s;
        s<<i;
        if(str=="")
            PrintCombinationOfNumberWithOnly1_2_3(s.str(),n-i,k);
        else
            PrintCombinationOfNumberWithOnly1_2_3(str + " " + s.str(),n-i,k);
    }
}
long long combinationOfNumberWithOnly1_2_3(long long n)
{
    long long arr[MAX],i;
    arr[1]=1;
    for(i=2;i<=n;i++)
    {
        arr[i]=0;
        if(i-1>0)
            arr[i]+=arr[i-1];
        if(i-2>0)
            arr[i]+=arr[i-2];
        if(i-3>0)
            arr[i]+=arr[i-3];
        if(i<=3)
            arr[i]++;
    }
    return(arr[n]);
}
int main()
{
    long long n;
    while(cin>>n)
    {
        cout<<combinationOfNumberWithOnly1_2_3(n)<<endl;
        PrintCombinationOfNumberWithOnly1_2_3("",n,3);
    }
    return 0;
}
