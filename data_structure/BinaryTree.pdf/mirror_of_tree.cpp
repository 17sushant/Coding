#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
void preorder(node *r)
{
     if(r==NULL)
          return;
     cout<<" ("<<r->data<<") ";
     preorder(r->left);
     preorder(r->right);
}

(node *) mirror(node *n)
{
    node *temp;
    temp=new node;
    temp-data=n->data;
}

int main()
{
    //making tree...
    struct node *a,*b,*c,*d,*e,*f,*g,*h,*i,*j,*k;

    a=new node;
    a->data=10;
    b=new node;
    b->data=3;
    c=new node;
    c->data=1;
    d=new node;
    d->data=1;
    e=new node;
    e->data=1;
    f=new node;
    f->data=0;
    g=new node;
    g->data=1;
    h=new node;
    h->data=2;
    i=new node;
    i->data=4;
    j=new node;
    j->data=1;
    k=new node;
    k->data=1;


    a->right=b;
    a->left=c;


    b->right=f;
    b->left=e;


    c->right=NULL;
    c->left=d;


    d->right=j;
    d->left=i;

    e->right=NULL;
    e->left=NULL;


    f->right=h;
    f->left=g;


    g->right=NULL;
    g->left=NULL;


    h->right=NULL;
    h->left=NULL;

    i->right=NULL;
    i->left=NULL;

    j->right=k;
    j->left=NULL;

    k->right=NULL;
    k->left=NULL;

    //finished making tree...

    cout<<"preorder traversal :"<<endl;
    preorder(a);
    cout<<endl;

    node *r;
    r=mirror(a);
    cout<<"Mirror tree has been formed"<<endl;
    cout<<"preorder traversal for mirrir tree :"<<endl;
    preorder(r);
    cout<<endl;

    return 0;
}
