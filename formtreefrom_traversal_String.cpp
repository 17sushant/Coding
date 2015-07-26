#include<iostream>
#include<string.h>
#include<queue>
#define MAX 100
using namespace std;

char *in;
char *pre;
int pos;
struct node
{
    int data;
    node *left;
    node *right;
};
void preorder(node *r)
{
    if(r!=NULL)
    {
        cout<<" ("<<(char)r->data<<") ";
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
        cout<<" ("<<(char)r->data<<") ";
    }
}
void inorder(node *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        cout<<" ("<<(char)r->data<<") ";
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
        cout<<"("<<(char)a->data<<") ";
    }
    cout<<endl;
}
int searchinorder(char ch)
{
    for(int i=0;i<strlen(in);i++)
        if(in[i]==ch)
            return i;
}
node *FormTree(int start,int end)
{
    if(start>end)
        return NULL;
    cout<<"pos "<<pos<<endl;
    int ri=searchinorder(pre[pos++]);
    cout<<"ri "<<ri<<endl;
    node * r=new node;
    r->data=in[ri];
    cout<<"rdata "<<(char)r->data<<endl;
    r->left=FormTree(start,ri-1);
    r->right=FormTree(ri+1,end);
    return r;
}
int main()
{
    //cout<<"enter preorder and inorder traversal"<<endl;
    //cin>>pre>>in;
    in="gdhbeiafjc";
    pre="abdgheicfj";
    int len=strlen(in);
    pos=0;
    node *root=FormTree(0,len-1);

    cout<<"post order traversal of the tree is "<<endl;
    postorder(root);cout<<endl;
    cout<<"pre order traversal of the tree is "<<endl;
    preorder(root);cout<<endl;
    cout<<"in order traversal of the tree is "<<endl;
    inorder(root);cout<<endl;
    cout<<"level order traversal of the tree is "<<endl;
    levelorder(root);cout<<endl;

    /*cout<<(char)root->data<<endl;
    cout<<(char)root->right->data<<endl;
    cout<<(char)root->left->data<<endl;
    cout<<(char)root->right->left->data<<endl;
    cout<<(char)root->right->left->right->data<<endl;
    cout<<(char)root->left->right->data<<endl;
    cout<<(char)root->left->right->right->data<<endl;
    cout<<(char)root->left->left->data<<endl;
    cout<<(char)root->left->left->left->data<<endl;
    cout<<(char)root->left->left->right->data<<endl;*/
    return 0;
}
