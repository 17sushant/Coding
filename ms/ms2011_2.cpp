#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
void swap(char *p, char *q)
{
    if(p==q)
        return;
    char temp=*p;
    *p=*q;
    *q=temp;
}
void fun(char * s,int st,int end)
{
    if(end<=st || st==end-1)
        return;
    int i,j,len,half;
    len=(end-st+1)/2;
    half=len/2;
    for(i=half,j=len;i<len,j<(len+half);i++,j++)
        swap(&s[st+i],&s[st+j]);
    int separator=2*half-1;
    if(len%2!=0)
        for(i=separator+1; i<separator+half+1;i++)
            swap(&s[st+i],&s[st+i+1]);
    //cout<<s<<endl<<st<<" "<<separator<<" "<<end;getchar();
    fun(s,st,st+separator);
    fun(s,st+separator+1,end);
}
int main()
{
    char arr[100]="0123456789abcdefghij";
    char arr1[100]="01234567abcdefgh";
    char arr2[100]="012345abcdef";
    char arr3[100]="0123abcd";
    char arr4[100]="01ab";
    fun(arr,0,strlen(arr)-1);
    cout<<arr<<endl;
    fun(arr1,0,strlen(arr1)-1);
    cout<<arr1<<endl;
    fun(arr2,0,strlen(arr2)-1);
    cout<<arr2<<endl;
    fun(arr3,0,strlen(arr3)-1);
    cout<<arr3<<endl;
    fun(arr4,0,strlen(arr4)-1);
    cout<<arr4<<endl;
    return 0;
}
