#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
void swap(char *a, char *b)
{
    if(a==b)
        return;
    char temp=*a;
    *a=*b;
    *b=temp;
}
void permutation(char *str,int i, int n)
{
    int j;
    if(i==n)
    {
        cout<<str<<endl;
        return;
    }
    for(j=i;j<n;j++)
    {
        swap(str+i,str+j);
        permutation(str,i+1,n);
        swap(str+i,str+j);   //backtrack...
    }
}

int main()
{
    char *str;
    while(cout<<"enter the string"<<endl && cin>>str)
        permutation(str,0,strlen(str));
    return 0;
}
