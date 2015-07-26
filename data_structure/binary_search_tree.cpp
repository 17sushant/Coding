#include<iostream>
using namespace std;
struct node
{
       int data;
       node *right;
       node *left;       
};
void insert(struct node **proot, int num)
{
     if(*proot==NULL)
     {
         (*proot)=new node;
         (*proot)->left=NULL;
         (*proot)->right=NULL;
         (*proot)->data=num;
         return;
     }
     else
     {
         if(num <((*proot)->data))
         {
                 insert((&(*proot)->left),num);          
         }     
         else
         {
                 insert(&((*proot)->right),num);    
         }
     }
     return;
}
void print_preorder(struct node *ptr)
{
     if(ptr!=NULL)
     {
          cout<<ptr->data<<" ";
          print_preorder(ptr->left);
          print_preorder(ptr->right);  
     }
     else
     {
         return;    
     }
}
void print_postorder(struct node *ptr)
{
     if(ptr!=NULL)
     {
          print_postorder(ptr->left);  
          print_postorder(ptr->right);  
          cout<<ptr->data<<" ";         
     }
     else
     {
         return;    
     }
}
void print_inorder(struct node *ptr)
{
     if(ptr!=NULL)
     {
          print_inorder(ptr->left);  
          cout<<ptr->data<<" ";         
          print_inorder(ptr->right);  
     }
     else
     {
         return;    
     }
}
int main()
{
    int n=10;
    int arr[10]={20,17,6,8,10,7,18,13,12,5},i;
    struct node *root=NULL;
    cout<<"enter the 10 elements to sort"<<endl;
    for(i=0;i<n;i++)
    {         
           cin>>arr[i];
           insert(&root,arr[i]);
    }
    cout<<"the binary search tree has been created"<<endl;
    cout<<endl;
    cout<<"Ascending order :"<<endl;
    print_inorder(root);
    
    cin>>i;
    delete(root);
    return 0;
}
