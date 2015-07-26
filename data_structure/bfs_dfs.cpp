#include<iostream>
#include<conio.h>
#include<cstring>
#include<math.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<utility>

#define INF (1<<31)-1
#define PI 3.1428571428571428571428571428571
#define MAXV(a,b) ( (a)>(b) ? (a) : (b) )
#define MINV(a,b) ( (a)<(b) ? (a) : (b) )
#define ABS(a) ( (a)>0 ? (a) : (-a) )
//int gcd(int a, int b){return (b? gcd(b,a%b):0);}
//int lcm(int a, int b) { return b*a/gcd(a,b); }
#define SETBIT(n,bit) ( (n) |= (1<<(bit)) )
#define CLEARBIT(n,bit) ( (n) &=  ~(1<<(bit)) )
#define CHECKBIT(n, bit)  ( (n) & (1 << (bit)) )
#define MAX 100
using namespace std;
int adj[MAX][MAX],color[MAX],d[MAX],p[MAX],value[MAX],times;
//color
//white ->-1   unvisited
//gray->1      the node has bene visited but not all its neighbouring nodes have been visited
//black->11    the node and all its neighbouring nodes are visited
void dfs_visit(int s, int n)
{
    stack<int> st;
    st.push(s);
    color[s]=1;
    while(!st.empty())
    {
        int i,k=st.top();
        st.pop();
        //cout<<"k "<<k;
        cout<<" ("<<value[k]<<") ";
        for(i=0;i<n;i++){
            if(adj[k][i]==1 && color[i]==-1)
            {
                cout<<"i here "<<i<<" ";
                st.push(i);
                color[k]=1;
            }
        }
        color[k]=11;
    }
}
void dfs(int val,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
       color[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        if(value[i]==val)
        {
            dfs_visit(i,n);
        }
    }

    for(i=0;i<n;i++)
        if(color[i]==-1)
            dfs_visit(i,n);
}
void bfs(int val,int n)
{
    queue<int> q;
    int i,j,s;
    for(i=0;i<n;i++)
    {
       color[i]=-1;
       d[i]=-1;
       p[i]=-1;
       if(value[i]==val)
            s=i;
    }
    q.push(s);
    color[s]=1;
    p[s]=-1;
    d[s]=0;
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        cout<<" ("<<value[k]<<") ";
        for(i=0;i<n;i++)
            if(adj[k][i]==1 && color[i]==-1)
            {
                q.push(i);
                p[i]=k;
                d[i]=d[k]+1;
                color[k]=1;
            }

        color[k]=11;
    }
    /*for(i=0;i<n;i++)
        if(color[i]==-1)
            bfs(val,n);*/
}
void bfs_shortest_path(int val1,int val2,int n)
{
    int s,e,i;
    for(i=0;i<n;i++)
    {
        if(value[i]==val2)
            e=i;
        if(value[i]==val1)
            s=i;
    }
    bfs(val1,n);
    cout<<"The shortest path length is "<<d[e]<<endl;
    cout<<"The shortest path is "<<endl;
    i=e;
    while(p[i]!=-1)
    {
        cout<<" ("<<value[i]<<") <-- ";
        i=p[i];
    }
    cout<<" ("<<value[s]<<")";
}
int main()
{
    int n,i,j,val,ans,val1,val2;
    //cout<<"enter no. of nodes in graph"<<endl;
    //cin>>n;
    n=5;
    //cout<<"enter the adjacency matrix"<<endl;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            //cin>>adj[i][j];
    adj={{0,1,0,1,1},
         {1,0,0,0,0},
         {0,0,0,1,0},
         {1,0,1,0,0},
         {1,0,0,0,0}
         };
    /*for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;}*/
    //cout<<"enter values of n nodes"<<endl;
    for(i=0;i<n;i++)
        //cin>>value[i];
    value={1,2,3,4,5};

    do
    {
        cout<<endl;
        cout<<"Graph Operation"<<endl;
        cout<<"---------------"<<endl;
        cout<<"1) DFS Traversal"<<endl;
        cout<<"2) BFS Traversal"<<endl;
        cout<<"3) Print Shortest Path(BFS)"<<endl;
        cout<<"4)Exit"<<endl;
        cout<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>ans;

        switch(ans)
        {
            case 1: cout<<"enter the starting node"<<endl;
                    cin>>val;
                    dfs(val,n);
                    break;
            case 2: cout<<"enter the starting node"<<endl;
                    cin>>val;
                    bfs(val,n);
                    break;
            case 3: cout<<"enter the starting and final node"<<endl;
                    cin>>val1>>val2;
                    bfs_shortest_path(val1,val2,n);
                    break;

        }
    }while(ans!=4);
    return 0;
}
