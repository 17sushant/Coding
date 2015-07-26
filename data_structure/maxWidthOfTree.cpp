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
int maxWidthBylevelorder(node *r)
{
    int nodesInCurrentLevel=1,nodesInNextLevel=0,maxWidth=1;
    queue<node *> q;
    q.push(r);
    while(!q.empty())
    {
        node *a=q.front();
        q.pop();
        --nodesInCurrentLevel;
        if(a->left!=NULL)
        {
            q.push(a->left);
            nodesInNextLevel++;
        }
        if(a->right!=NULL)
        {
            q.push(a->right);
            nodesInNextLevel++;
        }
        if(nodesInCurrentLevel==0)
        {
            nodesInCurrentLevel=nodesInNextLevel;
            nodesInNextLevel=0;
            if(nodesInCurrentLevel>maxWidth)
                maxWidth=nodesInCurrentLevel;
        }
    }
    return(maxWidth);
}
int main()
{
        node * root=NULL;
        insert(5,&root);insert(6,&root);insert(4,&root);insert(21,&root);insert(20,&root);
        insert(16,&root);insert(3,&root);insert(2,&root);insert(1,&root);insert(17,&root);
        insert(23,&root);
        cout<<maxWidthBylevelorder(root)<<endl;
    return 0;
}
