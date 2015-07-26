#include<iostream>
#include<queue>
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
void preorder(node *r)
{
    if(r!=NULL)
    {
        cout<<r->data<<" ";
        preorder(r->left);
        preorder(r->right);
    }
}
void postorder(node *r)
{
    if(r!=NULL)
    {
        postorder(r->left);
        postorder(r->right);
        cout<<r->data<<" ";
    }
}
void inorder(node *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        cout<<r->data<<" ";
        inorder(r->right);
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
node * kthMaxInBST(node *r,long long k,long long *p)
{
    if(r->left!=NULL)
    {
        node * x=kthMaxInBST(r->left,k,p);
        if(x!=NULL)
            return x;
    }
    //cout<<r->data<<" ";
    (*p)++;
    if((*p)==k)
        return r;
    if(r->right!=NULL)
    {
        node * x=kthMaxInBST(r->right,k,p);
        if(x!=NULL)
            return x;
    }

}
int main()
{
        long long ans,ele,k,i;
        node * root=NULL,*t;

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
            cout<<"8) kth maximum element in BST"<<endl;
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

                case 2: preorder(root);
                        cout<<endl;
                        break;

                case 3: postorder(root);
                        cout<<endl;
                        break;

                case 4: inorder(root);
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

                case 8: cout<<"enter value of k"<<endl;
                        cin>>k;
                        i=0;
                        t=kthMaxInBST(root,k,&i);
                        if(t==NULL)
                            cout<<"K is greater than no. of elements of tree"<<endl;
                        else
                            cout<<t->data<<endl;

                        break;

                default:return 0;
            }

        }while(ans!=0);
    return 0;
}
