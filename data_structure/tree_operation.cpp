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
void spiralLevelOrder(node *r)
{
    stack<node *> st1,st2,temp;
    st1.push(r);
    int LeftToRight=1;
    while(!st1.empty() || !st2.empty())
    {
        if(st1.empty())
        {
            LeftToRight*=-1;
            //swaing stack variables....
            temp=st1;
            st1=st2;
            st2=temp;
        }
        else
        {
            node * t=st1.top();
            cout<<t->data<<" ";
            st1.pop();
            if(LeftToRight>0)
            {
                if(t->right!=NULL)
                    st2.push(t->right);
                if(t->left!=NULL)
                    st2.push(t->left);
            }
            else
            {
                if(t->left!=NULL)
                    st2.push(t->left);
                if(t->right!=NULL)
                    st2.push(t->right);
            }
        }
    }
    cout<<endl;
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

//
void printLeft_Leaf_Edge(node *root,bool PrintOrNot)
{
    if(root!=NULL)
    {
        if(PrintOrNot==false)
        {
            if(root->left==NULL && root->right==NULL)
                cout<<root->data<<" ";
        }
        else
        {
            cout<<root->data<<" ";
        }
        printLeft_Leaf_Edge(root->left,PrintOrNot);
        printLeft_Leaf_Edge(root->right,PrintOrNot && (root->left==NULL)?true:false);
    }
}
void printRightEdge(node *root)
{
    if(root!=NULL)
    {
        /*printRightEdge(root->left,PrintOrNot && (root->right==NULL?true:false));
        printRightEdge(root->right,PrintOrNot);
        if(PrintOrNot==false)
        {
            if(root->right==NULL && root->left==NULL)
                cout<<root->data<<" ";
        }
        else
        {
            cout<<root->data<<" ";
        }*/
        printRightEdge(root->right);
        if(root->right==NULL)
            printRightEdge(root->left);
        if(root->left!=NULL || root->right!=NULL)
            cout<<root->data<<" ";
    }
}
void outerBoundary(node *root)
{
    if(root!=NULL)
    {
        printLeft_Leaf_Edge(root,true);
        printRightEdge(root);
    }

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
            cout<<"6) Spiral Level order Traversal"<<endl;
            cout<<"7) Print Outer Boundary of the tree"<<endl;
            cout<<"8) Tree Height"<<endl;
            cout<<"9) find the nth inorder data..."<<endl;
            cout<<endl;
            cout<<endl<<"Enter any option"<<endl<<endl;
            cin>>ans;
            switch(ans)
            {

                case 1: //cout<<"enter the element to enter into the tree"<<endl;
                        //cin>>ele;
                        //insert(ele,&root);
                        //insert(5,&root);insert(6,&root);insert(4,&root);insert(21,&root);insert(20,&root);
                        //insert(16,&root);insert(3,&root);insert(2,&root);insert(1,&root);insert(17,&root);
                        insert(15,&root);insert(26,&root);insert(30,&root);insert(20,&root);insert(27,&root);
                        insert(10,&root);insert(37,&root);insert(12,&root);insert(11,&root);
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

                case 6: spiralLevelOrder(root);
                        break;

                case 7: outerBoundary(root);
                        break;

                case 8: cout<<"Max Tree height is "<<tree_height(root)<<endl;
                        break;

                case 9: long long n,val;
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
