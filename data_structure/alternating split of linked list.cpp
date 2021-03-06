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
          *p=temp;
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
void deletes(struct node **p,int ele)
{
     if(*p==NULL)
         cout<<"List is empty"<<endl;
     else if(num_ele(*p)==1)
     {
          *p=NULL;
     }
     else
     {
         struct node *t;
         t=*p;
         while((t->link)->info!=ele && t->link!=NULL)///some prob here.......
         {
              t=t->link;
         }
         t->link=(t->link)->link;
     }

}
void alternativeSplit(node *s,node **s1, node **s2)
{
    if(s==NULL)
    {
        *s1=NULL;
        *s2=NULL;
        return;
    }
    node *a,*b,*temp;
    *s1=s;
    *s2=s->link;
    if(s->link!=NULL)
    {
        alternativeSplit(s->link->link,&a,&b);
        temp=s->link;
        s->link=a;
        temp->link=b;
    }
}
int main()
{
    int ans;
    struct node *start=NULL;
    struct node *st1=NULL,*st2=NULL;
    do
    {
                cout<<"Linled List Operations"<<endl;
                cout<<"----------------------"<<endl<<endl;
                cout<<"1)Display"<<endl;
                cout<<"2)Number of elements"<<endl;
                cout<<"3)Add element in the beggining"<<endl;
                cout<<"4)Add element at the end"<<endl;
                //cout<<"5)Add element"<<endl;
                cout<<"5) Sort the linked list"<<endl;
                cout<<"6)Delete a specified element"<<endl;
                cout<<"7)Split the linked list alternatively"<<endl;
                cout<<"8)Exit"<<endl;
                cout<<"_____________________________"<<endl<<endl;
                cout<<"Enter option"<<endl;
                cin>>ans;

                switch(ans)
                {
                      int ele,pos;
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
                             cout<<"enter the element to add"<<endl;
                             cin>>ele;
                             cout<<"enter the position u want to add it to"<<endl;
                             cin>>pos;
                             //add(&start,ele,pos);
                             break;
                      case 6:
                             cout<<"which element to delete"<<endl;
                             cin>>ele;
                             deletes(&start,ele);
                             break;
                      case 7:
                             alternativeSplit(start,&st1,&st2);
                             start=NULL;
                             cout<<"First List"<<endl;
                             display(st1);
                             cout<<endl<<"Second List"<<endl;
                             display(st2);
                             cout<<endl;
                             break;

                      case 8:
                             break;
                      deafult:
                              cout<<"Please enter valid option(1-8)"<<endl;
                }

    }while(ans!=8);
    return 0;
}
