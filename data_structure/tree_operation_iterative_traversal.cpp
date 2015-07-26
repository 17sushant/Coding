#include<iostream>
#include<queue>
#include<stack>
#define MAX(a,b) ((a>b)?a:b)
using namespace std;
struct node
{
    long long data;
    node * left;
    node * right;
};
/*void nthinorder(node *r,long long n,long long *valp,node **ap)
{
    if(r==NULL)
        return;
    if(*valp!=n)
        nthinorder(r->left,n,valp,ap);
    if(*valp!=n)
    {
        *valp=*valp+1;
        //cout<<*valp<<" as ";
    }
    if(*valp!=n)
        nthinorder(r->right,n,valp,ap);

    if(*valp==n)
    {
        *ap=r;
        return;
    }
}*/


int tree_height(node * root)
{
    if(root==NULL)
        return 0;
    return( (MAX(tree_height(root->left),tree_height(root->right))) + 1 );
}
void insert(long long e,node **r)
{
    if(*r==NULL)
    {
        node *p=new node;
        p->data=e;
        p->left=NULL;
        p->right=NULL;
        *r=p;
    }
    else
    {
        if(e>=(*r)->data)
        {
            insert(e,&((*r)->right));
        }
        else
            insert(e,&((*r)->left));
    }
}
void iterativePreorder(node *r)
{
    node *ptr=r;
    stack<node *> st;
    while(!st.empty() || ptr!=NULL)
    {
        if(ptr!=NULL)
        {
            cout<<ptr->data<<" ";
            st.push(ptr);
            ptr=ptr->left;
        }
        else
        {
            ptr=st.top();
            st.pop();
            ptr=ptr->right;
        }

    }
}
/*void iterativePostorder(node *r)
{
    node *ptr=r;
    stack<node *> st;
    while(!st.empty() || ptr!=NULL)
    {
        if(ptr!=NULL)
        {
            st.push(ptr);
            ptr=ptr->left;
        }
        else
        {
             n
        }
    }
}*/
void iterativeInorder(node *r)
{
    node *ptr=r;
    stack<node *> st;
    while(!st.empty() || ptr!=NULL)
    {
        if(ptr!=NULL)
        {
            st.push(ptr);
            ptr=ptr->left;
        }
        else
        {
            ptr=st.top();
            st.pop();
            cout<<ptr->data<<" ";
            ptr=ptr->right;
        }
    }
}
void levelorder(node *r)
{
    queue<node *> q;
    q.push(r);
    while(!q.empty())
    {
        node *a=q.front();
        q.pop();
        if(a->left!=NULL)
            q.push(a->left);
        if(a->right!=NULL)
            q.push(a->right);
        cout<<"("<<a->data<<") ";
    }
    cout<<endl;
}
int main()
{
        long long ans,ele;
        node * root=NULL;

        do
        {
            cout<<endl;
            cout<<"Binary Search Tree Operations"<<endl;
            cout<<"-----------------------------"<<endl;
            cout<<"0) Exit"<<endl;
            cout<<"1) Insert Tree"<<endl;
            cout<<"2) Preorder Traversal"<<endl;
            cout<<"3) Postorder Traversal"<<endl;
            cout<<"4) Inorder Traversal"<<endl;
            cout<<"5) Level order Traversal"<<endl;
            cout<<"6) Tree Height"<<endl;
            cout<<"7) find the nth inorder data..."<<endl;
            cout<<endl;
            cout<<endl<<"Enter any option"<<endl<<endl;
            cin>>ans;
            switch(ans)
            {

                case 1: //cout<<"enter the element to enter into the tree"<<endl;
                        //cin>>ele;
                        //insert(ele,&root);
                        insert(5,&root);insert(6,&root);insert(4,&root);insert(21,&root);insert(20,&root);
                        insert(16,&root);insert(3,&root);insert(2,&root);insert(1,&root);insert(17,&root);
                        break;

                case 2: iterativePreorder(root);
                        cout<<endl;
                        break;

                case 3: //iterativePostorder(root);
                        cout<<endl;
                        break;

                case 4: iterativeInorder(root);
                        cout<<endl;
                        break;

                case 5: levelorder(root);
                        break;

                case 6: cout<<"Max Tree height is "<<tree_height(root)<<endl;
                        break;

                case 7: long long n,val;
                        val=1;
                        cout<<"Enter n "<<endl;
                        cin>>n;
                        node *a;
                        //nthinorder(root,n,&val,&a);
                        cout<<a->data<<endl;
                        break;

                default:return 0;
            }

        }while(ans!=0);
    return 0;
}
