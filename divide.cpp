#include<iostream>
using namespace std;
int divide(int a,int b)
{
    if(a<b)
        return 0;
    else
        return (1 + divide(a-b,b));
}
int main()
{
    cout<<divide(23,4);
    return 0;
}
