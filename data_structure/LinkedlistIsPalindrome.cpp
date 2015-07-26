#include<iostream>
using namespace std;
struct node
{
       int info;
       struct node *link;
};

void display(struct node *p)
{
     while(p!=NULL)
     {
          cout<<"| ";
          cout<<p->info;
          cout<<" | -->";
          p=p->link;
     }
     cout<<" NULL"<<endl<<endl<<endl;
}
int num_ele(struct node *p)
{
    int count=0;
    while(p!=NULL)
     {
          p=p->link;
          count++;
     }
     return count;
}
void addbeg(struct node **p,int ele)
{
     struct node *temp;
     temp=new node;
     temp->info=ele;
     temp->link=*p;
     *p=temp;
}
void addend(struct node **p,int ele)
{
     struct node *temp,*r;
     temp=new node;
     temp->info=ele;
     temp->link=NULL;
     if(*p==NULL)
     {
         *p=temp;
         return;
     }
     r=*p;
     if(r!=NULL)
     {
          while(r->link!=NULL)
          {
                r=r->link;
          }
          r->link=temp;
     }
}

bool isPalin(node **left, node *right)
{
    if(*left==NULL)
        return false;

    if(right==NULL)
        return true;
    bool a=isPalin(left,right->link);
    if(a==false)
        return false;

    if((*left)->info!=right->info)
        return false;
    else
    {
        *left=(*left)->link;
        return true;
    }
}
int main()
{
    int ans;
    struct node *start=NULL;
    do
    {
                cout<<"Linled List Operations"<<endl;
                cout<<"----------------------"<<endl<<endl;
                cout<<"1)Display"<<endl;
                cout<<"2)Number of elements"<<endl;
                cout<<"3)Add element in the beggining"<<endl;
                cout<<"4)Add element at the end"<<endl;
                cout<<"5)Find if the linked list is Palindrome "<<endl;
                cout<<"6)Exit"<<endl;
                cout<<"_____________________________"<<endl<<endl;
                cout<<"Enter option"<<endl;
                cin>>ans;

                switch(ans)
                {
                      int ele,pos;
                      node *st;
                      case 1:
                             display(start);
                             break;
                      case 2:
                             cout<<num_ele(start)<<endl;
                             break;
                      case 3:
                             cout<<"enter the element to add"<<endl;
                             cin>>ele;
                             addbeg(&start,ele);
                             break;
                      case 4:
                             cout<<"enter the element to add"<<endl;
                             cin>>ele;
                             addend(&start,ele);
                             break;
                      case 5:
                             st=start;
                             if(isPalin(&st,st))
                                cout<<"YES"<<endl;
                             else
                                cout<<"NO"<<endl;
                             break;
                      case 6:
                             break;
                      deafult:
                              cout<<"Please enter valid option(1-6)"<<endl;
                }

    }while(ans!=6);
    return 0;
}
