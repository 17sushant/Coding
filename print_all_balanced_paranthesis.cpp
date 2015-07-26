#include<iostream>
using namespace std;
void printParanthesis(int toOpen, int toClose,string s)
{
    if(toOpen==0 && toClose==0)
        cout<<s<<endl;
    if(toOpen>0)
        printParanthesis(toOpen-1,toClose+1,s+'{');
    if(toClose>0)
        printParanthesis(toOpen,toClose-1,s+'}');
}
int main()
{
    int n;
    while(cin>>n)
    {
        printParanthesis(n,0,"");
        cout<<endl;
    }
    return 0;
}
