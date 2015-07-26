//Given Preorder traversal of a BST, check if each non-leaf node has only one child.
//Assume that the BST contains unique entries
#include<iostream>
#define INF ((1<<31) -1)
using namespace std;
bool isTreeContainOnlySingleChild(int pre[],int n)
{
    int i,max=INF,min=-1*INF;
    for(i=0;i<n;i++)
    {
        if(pre[i]>max || pre[i]<min)
            return false;
        if(i+1<n)
        {
            if(pre[i+1]>pre[i])
                min=pre[i];
            else
                max=pre[i];
        }
    }
    return true;
}
int main()
{
    int pre[]={20,10,15,19,17},n=5;
    if(isTreeContainOnlySingleChild(pre,n))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}




node *constructTreeUtil(int pre[], char preLN[], int *index_ptr, int n)
{
    int index = *index_ptr;
    if (index == n)
        return NULL;
     node *temp = new node (pre[index] );
     node->data=pre[index];
    (*index_ptr)++;
    if (preLN[index] == 'N')
    {
        temp->left  = constructTreeUtil(pre, preLN, index_ptr, n);
        temp->right = constructTreeUtil(pre, preLN, index_ptr, n);
    }
    return temp;
}
