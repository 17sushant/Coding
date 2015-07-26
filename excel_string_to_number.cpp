#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
long long excelNumber(char *str)
{
    int num=0,len=strlen(str),i;
    for(i=len-1;i>=0;i--)
        num+=pow(26,i)*(str[len-i-1] - 'A' + 1);
    return num;
}
int main()
{
    cout<<excelNumber("AXZ")<<endl;
    cout<<excelNumber("XZ")<<endl;
}
