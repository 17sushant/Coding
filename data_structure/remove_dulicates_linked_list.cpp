#include<iostream>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<utility>

#define INF (1<<31)-1
#define PI 3.1428571428571428571428571428571
#define MAXV(a,b) ( (a)>(b) ? (a) : (b) )
#define MINV(a,b) ( (a)<(b) ? (a) : (b) )
#define ABS(a) ( (a)>0 ? (a) : (-a) )
//int gcd(int a, int b){return (b? gcd(b,a%b):0);}
//int lcm(int a, int b) { return b*a/gcd(a,b); }
#define SETBIT(n,bit) ( (n) |= (1<<(bit)) )
#define CLEARBIT(n,bit) ( (n) &=  ~(1<<(bit)) )
#define CHECKBIT(n, bit)  ( (n) & (1 << (bit)) )
using namespace std;

struct node
{
    int data;
    node *link;
};

node * insert()
{
    node *r=NULL,*ptr,*temp;
    int ele;
    cin>>ele;
    do
    {
        temp=new node;
        temp->data=ele;
        temp->link=NULL;
        if(r==NULL)
        {
            r=temp;
            ptr=temp;
        }
        else
        {
            ptr->link=temp;
            ptr=temp;
        }
        cin>>ele;
    }while(ele!=-1);
    return r;
}
void traverse(node *t)
{
    while(t!=NULL)
    {
        cout<<t->data<<" -> ";
        t=t->link;
    }
    cout<<" NULL"<<endl;
}
void find_duplicates()
{
    sort();
}
int main()
{
    int a;
    node *root=NULL;
    cout<<"Insert elements into linked list(-1 to terminate)"<<endl;
    root=insert();
    traverse(root);
    find_duplicates(root);
    return 0;
}
