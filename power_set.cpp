#include<iostream>
#include<math.h>
using namespace std;
void printPowerSet(char s[],int n)
{
    int pn=pow(2,n);
    int i,j=pn>>1,k=0;
    for(i=0;i<pn;i++)
    {
        cout<<"{";
        k=0;
        j=pn>>1;
        while(j)
        {
            if(i&j)
                cout<<s[k]<<" ";
            j=j>>1;
            k++;
        }
        cout<<"}"<<endl;
    }
}
int main()
{
    char arr[5]={'a','b','c'};
    printPowerSet(arr,3);
    return 0;
}
