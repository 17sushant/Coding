#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;
struct node
{
    void *data;
    int size;
    node *link;
};
void insert(node **h,void *p,int s)
{
    node *tt,*temp=new node;
    void *x=malloc(s);
    for(int i=0;i<s;i++)
        *((char *)x+i)=*((char *)p+i);
    temp->data=x;
    temp->link=NULL;
    temp->size=s;
    if(*h==NULL)
    {
        *h=temp;
    }
    else
    {
        tt=*h;
        while(tt->link!=NULL)
            tt=tt->link;
        tt->link=temp;
    }
}
void printint(void *p)
{
    cout<<*((int *)p)<<" ";
}
void printchar(void *p)
{
    cout<<*((char *)p)<<" ";
}
void printfloat(void *p)
{
    cout<<*((float *)p)<<" ";
}
void traverse(node *h)
{
    while(h!=NULL)
    {
        //print...
        void (*funptr)(void *);
        if(h->size==sizeof(int))
            funptr=printint;
        else if(h->size==sizeof(char))
            funptr=printchar;
        else if(h->size==sizeof(float))
            funptr=printfloat;
        (*funptr)(h->data);
        h=h->link;
    }
}
int main()
{
    int a=3,b=12,c=34,d=54;
    float e=3.14,f=1.2,g=2.2;
    char h='A',i='B',j='C';
    node *head=NULL;
    insert(&head,&a,sizeof(a));
    insert(&head,&e,sizeof(e));
    insert(&head,&h,sizeof(h));
    insert(&head,&b,sizeof(b));
    insert(&head,&f,sizeof(f));
    insert(&head,&i,sizeof(i));
    insert(&head,&c,sizeof(c));
    insert(&head,&g,sizeof(g));
    insert(&head,&j,sizeof(j));

    cout<<"insertions over"<<endl;
    getchar();
    traverse(head);
    return 0;
}
