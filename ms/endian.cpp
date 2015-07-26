#include<iostream>
using namespace std;
int main()
{
    int n=127;
    int *p = &n;
    char *c=(char *)p;
    if(*c==n)
        cout<<"little endian"<<endl;
    else if(*(c+sizeof(int)-1) ==n)
        cout<<"Big endian"<<endl;
    else
        cout<<"no way"<<endl;

    return 0;
}
