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
int tree_height(node * root)
{
    if(root==NULL)
        return 0;
    return( (MAX(tree_height(root->left),tree_height(root->right))) + 1 );
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
int main()
{
        long long ans,ele;
        node * root=NULL;
        do
        {
            cout<<endl;
            cout<<"AVL Tree Operations"<<endl;
            cout<<"-----------------------------"<<endl;
            cout<<"0) Exit"<<endl;
            cout<<"1) Insert To Tree"<<endl;
            cout<<"2) Delete From Tree"<<endl;
            cout<<"3) Preorder Traversal"<<endl;
            cout<<"4) Postorder Traversal"<<endl;
            cout<<"5) Inorder Traversal"<<endl;
            cout<<"6) Level order Traversal"<<endl;
            cout<<"7) Tree Height"<<endl;
            cout<<endl;
            cout<<endl<<"Enter any option"<<endl<<endl;
            cin>>ans;
            switch(ans)
            {

                case 1:
                        break;

                case 3: preorder(root);
                        cout<<endl;
                        break;

                case 4: postorder(root);
                        cout<<endl;
                        break;

                case 5: inorder(root);
                        cout<<endl;
                        break;

                case 6: levelorder(root);
                        break;

                case 7: cout<<"Max Tree height is "<<tree_height(root)<<endl;
                        break;
                default:cout<<"enter given options only"<<endl;
            }

        }while(ans!=0);
    return 0;
}
