#include<iostream>
using namespace std;
struct node
{
       int data;
       struct node *XORLink;
};
node *XOR(node *a, node *b)
{
    return ((node *)((long long)(a) ^ (long long)(b)) );
}
void display(node *st)
{
    node *prev=NULL,*curr=st,*temp;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        temp=curr;
        curr=XOR(curr->XORLink,prev);
        prev=temp;
    }
    cout<<endl;
}
void addatend(node **st,int ele)
{
    node *prev,*curr,*temp;
    node *nn=new node;
    nn->data=ele;
    if(*st==NULL)
    {
        *st=nn;
        nn->XORLink=XOR(NULL,NULL);
        return;
    }
    prev=NULL;curr=*st;
    while(curr!=NULL)
    {
        temp=curr;
        curr=XOR(curr->XORLink,prev);
        prev=temp;
    }
    nn->XORLink=XOR(prev,NULL);
    node* l = XOR((prev)->XORLink,  NULL);
    prev->XORLink=XOR(l,nn);
}
void addatbeg(node **st,int ele)
{
    node *nn=new node;
    nn->data=ele;
    nn->XORLink=XOR(NULL,*st);
    if(*st!=NULL)
    {
        node* l = XOR((*st)->XORLink,  NULL);
        (*st)->XORLink = XOR(nn, l);
    }
    *st=nn;
}
void del(node **st, int ele)
{

}
int main()
{
    int ans;
    struct node *start=NULL;
    do
    {
                cout<<endl<<endl;
                cout<<"XOR Doubly Linled List Operations"<<endl;
                cout<<"----------------------"<<endl<<endl;
                cout<<"1)Display"<<endl;
                cout<<"2)Add element in the beggining"<<endl;
                cout<<"3)Add element at the end"<<endl;
                cout<<"4)Delete a specified element"<<endl;
                cout<<"5)Exit"<<endl;
                cout<<"_____________________________"<<endl<<endl;
                cout<<"Enter option"<<endl;
                cin>>ans;

                switch(ans)
                {
                    int ele;
                    case 1:
                            display(start);
                            break;
                    case 2:
                            cout<<"enter the element to insert"<<endl;
                            cin>>ele;
                            addatbeg(&start,ele);
                            break;
                    case 3:
                            cout<<"enter the element to insert"<<endl;
                            cin>>ele;
                            addatend(&start,ele);
                            break;
                    case 4:
                            cout<<"enter the element to delete"<<endl;
                            cin>>ele;
                            del(&start,ele);
                            break;
                    case 5:
                            break;
                    default:cout<<"enter option from 1-5 "<<endl;
                }

    }while(ans!=5);
    return 0;
}
