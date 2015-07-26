#include<iostream>
using namespace std;
int myatoi2(char *p)
{
    int neg=0,num=0;
    while(*p!='\0')
    {
        if(*p=='+' && ( *(p+1)>=48 && *(p+1)<=56 ) )
            neg=0;
        else if(*p=='-' && ( *(p+1)>=48 && *(p+1)<=56 ) )
            neg=1;
        else if(*(p)>=48 && *(p)<=56 )
        {
            num=num*10+(*p-48);
        }
        else
        {
            if(num!=0)
                break;
        }
        p++;
    }
    return ((neg==1)?-1*num:num);
}
int myatoi(char *p)
{
    if(*p==NULL)
        return 0;
    char *s=p;
    int neg=0,i=0,num=0;
    while(*s)
    {
        if(i==0)
        {
            if(*s=='+')
            {
                s++;
                continue;
            }
            else if(*s=='-')
            {
                s++;
                neg=1;
                continue;
            }
        }
        if(*s>='0' && *s <='9')
        {
            num*=10;
            num+=*s-48;
            s++;
        }
        else
        {
            if(neg==1)
                return (-1*num);
            else
                return num;
        }
    }

}
int main()
{
    cout<<"myatoi"<<endl<<endl;
    cout<<myatoi("asdadda")<<endl;
    cout<<myatoi("+1231asdadda")<<endl;
    cout<<myatoi("+asdadda")<<endl;
    cout<<myatoi("-3424asdfds342adda")<<endl;
    cout<<myatoi("434a32sdadda")<<endl;
    cout<<"myatoi2"<<endl<<endl;
    cout<<myatoi2("asdadda")<<endl;
    cout<<myatoi2("+1231asdadda")<<endl;
    cout<<myatoi2("+asdadda")<<endl;
    cout<<myatoi2("-3424asdfds342adda")<<endl;
    cout<<myatoi2("434a32sdadda")<<endl;
    cout<<myatoi2("sadsa+fdfe-sadsas-434a32sdadda")<<endl;
    return 0;
}
