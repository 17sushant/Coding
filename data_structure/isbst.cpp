#include<iostream>
using namespace std;
struct node
{
    long long data;
    node *left;
    node *right;
};
bool isBST(node *r, long long *lastdata)
{
    if(r==NULL)
        return (false);

    bool a=true,b=true,c=true;
    if((r->left)!=NULL)
        a=isBST(r->left,lastdata);
    if((r->data)>*lastdata)
    {
        *lastdata=r->data;
        b=true;
    }
    else
        b=false;
    if((r->right)!=NULL)
        c=isBST(r->right,lastdata);
    return(a && b && c);
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

    long long lastdata=-1231312;
    if(isBST(root,&lastdata))
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}
