#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char *findstr;
    char *src;
    char *replacestr;
    cout<<"enter src findstr and replacestr"<<endl;
    while(cin>>src>>findstr>>replacestr)
    {
        cout<<src<<endl<<findstr<<endl<<replacestr<<endl;
    }
    return 0;
}
