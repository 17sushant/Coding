#include<iostream>
#include<queue>
using namespace std;
struct node
{
       int info;
       node *left;
       node *right;
};
void insert(int a,node **r)
{
     if(*r==NULL)
     {
          *r=new node;
          (*r)->info=a;       
          (*r)->left=NULL;
          (*r)->right=NULL; 
          return;         
     }
     if(((*r)->info)<a)
         insert(a,&((*r)->right));
     if(((*r)->info)>=a)            
         insert(a,&((*r)->left));
     return;
}
void inorder(node *r)
{
     if(r==NULL)
          return;
     inorder(r->left);
     cout<<" ("<<r->info<<") ";     
     inorder(r->right);
}
void preorder(node *r)
{
     if(r==NULL)
          return;
     cout<<" ("<<r->info<<") ";     
     preorder(r->left);
     preorder(r->right);
}
void postorder(node *r)
{
     if(r==NULL)
          return;
     postorder(r->left);
     postorder(r->right);
     cout<<" ("<<r->info<<") ";     
}
void levelorder(node *r)
{
     queue<node *> q;
     q.push(r);
     while(!q.empty())
     {
          node *t=q.front();
          q.pop();
          if((t->left)!=NULL)
                q.push(t->left);
          if((t->right)!=NULL)
                q.push(t->right);                
          cout<<" ("<<t->info<<") ";
     }     
     cout<<endl;
     return;
}
int main()
{
    node *root=NULL;
    int q=0;
    do
    {
        cout<<endl;
        cout<<"Binary Search Tree Operations"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) Insert Tree"<<endl;
        cout<<"2) Preorder Traversal"<<endl;
        cout<<"3) Postorder Traversal"<<endl;
        cout<<"4) Inorder Traversal"<<endl;
        cout<<"5) Level order Traversal"<<endl;
        cout<<"6) Exit"<<endl;
        cout<<endl<<"Enter any option"<<endl<<endl;
        int ans;
        cin>>ans;
        switch(ans)
        {
             case 2:
                  preorder(root);
                  break;
             case 3:
                  postorder(root);
                  break;
             case 4:
                  inorder(root);
                  break;
             case 1:
                  int a;
                  cout<<"Enter the number"<<endl;
                  cin>>a;
                  insert(a,&root);
                  break;   
             case 5:
                  levelorder(root);
                  break;
             case 6:
                  cout<<"BYEBYE"<<endl;
                  q=1;
                  
        }  
    }while(q==0);  
    return 0;
}
