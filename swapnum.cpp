#include<iostream>
void swap_add(int *a,int*b)
{
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}
void swap_xor(int *a,int*b)
{
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        swap_add(&a,&b);
        cout<<"after swap add "<<a<<" "<<b<<endl;
        //swap_xor(&a,&b);
        //cout<<"after swap xor "<<a<<" "<<b<<endl;
    }

    return 0;
}
