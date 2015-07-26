#include<iostream>
using namespace std;
void printBalancedParentheses(string str, int toOpen, int toClose)
{
    if(toOpen==0 && toClose==0)
    {
        cout<<str<<endl;
        return;
    }
    if(toOpen>0)
        printBalancedParentheses(str+"(",toOpen-1,toClose+1);
    if(toClose>0)
        printBalancedParentheses(str+")",toOpen,toClose-1);
}
int main()
{
    int n;
    while(cin>>n)
    {
        printBalancedParentheses("",n,0);
    }
    return 0;
}
