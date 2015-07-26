#include<iostream>
#define INF ((1<<31)-5)
using namespace std;
struct node
{
    long long data;
    node *left;
    node *right;
};
bool isBST(node *r, long long max, long long min)
{
    if(r==NULL)
        return true;
    if(r->data < max && r->data > min && isBST(r->left,r->data,min) && isBST(r->right,max,r->data-1))
        return true;
    //cout<<r->data<<" "<<max<<" "<<min<<endl;
    return false;
}
int main()
{
    node *root,*t,*l,*r,*r1,*r2;

    t=new node;
    t->left=NULL;
    t->right=NULL;
    t->data=14;

    l=new node;
    l->left=NULL;
    l->right=NULL;
    l->data=8;

    r=new node;
    r->left=t;
    r->right=NULL;
    r->data=16;

    r1=new node;
    r1->left=NULL;
    r1->right=r;
    r1->data=10;

    r2=new node;
    r2->left=NULL;
    r2->right=l;
    r2->data=8;

    root=new node;
    root->left=r2;
    root->right=r1;
    root->data=10;


    if(isBST(root,INF,-1*INF))
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}
