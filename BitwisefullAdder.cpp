#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
string addBinary(string a, string b)
{
    string str="";
    char carr[1];
    int i,j,k,la,lb,s,c=0,x,y;
    la=a.length();
    lb=b.length();

    i=la-1;j=lb-1;
    while(i>=0 || j>=0)
    {
        if(i>=0)
            x=a[i]-48;
        else
            x=0;
        if(j>=0)
            y=b[j]-48;
        else
            y=0;

        s=x^y^c;
        c=x&y | y&c | c&x;
        sprintf(carr,"%d",s);
        str= carr[0] + str;
        if(i>=0)
            i--;
        if(j>=0)
            j--;
    }
    if(c==1)
        str="1"+str;
    return str;
}
int main()
{
    cout<<addBinary("11","1");
    return 0;
}
