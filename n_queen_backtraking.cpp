#include<iostream>
#include<cstdlib>
using namespace std;
int sol_mat[100];
bool isSafe(int k,int n)
{
    if(k>=n)
        return false;
    for(int i=0;i<k;i++)
    {
        if(sol_mat[k]==sol_mat[i] || ( abs(sol_mat[k]-sol_mat[i])==abs(k-i) ) )
            return false;
    }
    return true;
}
bool n_queen(int k,int n)
{
    if(k>=n)
        return true;
    for(sol_mat[k]=0;sol_mat[k]<n;sol_mat[k]++)
    {
        cout<<"k sol_mat "<<k<<" "<<sol_mat[k]<<""<<endl;
        if(isSafe(k,n))
        {
            cout<<"k sol_mat "<<k<<" "<<sol_mat[k]<<"safe"<<endl;
            if(n_queen(k+1,n))
                return true;
            else
                continue;
        }
    }
    return false;
}
int main()
{
    int n,i;
    cout<<"enter n"<<endl;
    cin>>n;
    if(n_queen(0,n))
    {
        for(i=0;i<n;i++)
            cout<<sol_mat[i]<<" ";
        cout<<endl;
    }
    else
        cout<<"no such arrangement exists"<<endl;
    return 0;
}
