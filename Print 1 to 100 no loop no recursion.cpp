#include<iostream>
#include<cstdio>
using namespace std;
class A
{
        public:
        A()
        {
            static int i=0;
            i++;
            cout<<i<<endl;
        }
};
int main()
{
        A obj[100];
        return 0;
}
