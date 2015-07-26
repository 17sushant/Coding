#include<iostream>
#include<math.h>
using namespace std;
int mostSignificatDigit(int n)
{
    int r;
    while(n>0)
    {
        r=n%10;
        n/=10;
    }
    return r;
}
int numberOfDigit(int n)
{
    int d=0;
    while(n>0)
    {
        d++;
        n/=10;
    }
    return d;
}
int countNumContaining3(int n)
{
    if(n<3)
        return 0;
    if(n<=9)
        return(1);
    int count=0,msd=mostSignificatDigit(n),d=numberOfDigit(n),x,p;
    p=pow(10,d-1);
    x=countNumContaining3(p-1);
    count+=x;
    if(msd<3)
        count+=(msd-1)*x;
    else if(msd>3)
        count+=(msd-2)*x+p;
    else//msd=3
        count+=(msd-1)*x+(n%p);
    if(msd!=3)
        count+=countNumContaining3(n%p);
    return count;
}
int main()
{
    int n;
    while(cin>>n)
    {
        cout<<(n-countNumContaining3(n))<<endl;
    }
    return 0;
}

