#include<iostream>
#include<stack>
#include<queue>
using namespace std;
long long adj[100][100],value[100],d[100],P[100],times,de[100],f[100];
char color[100];
void dfs_visit(long long u,long long n)
{
     long long v;
     color[u]='g';
     times=times+1;
     de[u]=times;
     for(v=1;v<=n;v++)
     {
          if(adj[u][v]==1 && color[v]=='w')
          {
                 P[v]=u;
                 dfs_visit(v,n);
          }
     }
     cout<<" ("<<value[u]<<") ";
     color[u]='b';
     f[u]=times+1;
}
void dfs(long long val,long long n)
{
     long long i,s=1;
     for(i=1;i<=n;i++)
     {
          if(value[i]==val)
                s=i;
          color[i]='w';
          P[i]=-1;
     }
     times=0;
     for(i=1;i<=n;i++)
     {
           if(color[i]=='w')
                dfs_visit(i,n);
     }
}
void bfs(long long val,long long n)
{
     queue<long long> q;
     long long i,s=1;
     for(i=1;i<=n;i++)
     {
          if(value[i]==val)
                s=i;
          color[i]='w';
          d[i]=9999999;         //means infinity
          P[i]=-1;
     }
     color[s]='g';
     d[s]=0;
     P[s]=-1;
     q.push(s);
     while(!q.empty())
     {
           long long v,u=q.front();
           q.pop();
           for(v=1;v<=n;v++)
           {
              if(adj[u][v]==1 && color[v]=='w')
              {
                    color[v]='g';
                    d[v]=d[u]+1;
                    P[v]=u;
                    q.push(v);
              }
           }
           cout<<" ("<<value[u]<<") ";
           color[u]='b';

     }
     for(i=1;i<=n;i++)
          if(color[i]=='w')
          {
              bfs(i,n);
          }
}
void shortest_path(long long from, long long to, long long n)
{
     long long i,from_i,to_i;
     for(i=1;i<=n;i++)
     {
          if(value[i]==from)
                from_i=i;
          if(value[i]==to)
                to_i=i;
     }
     if(from_i==to_i)
          cout<<from<<endl;
     else if(P[to_i]==-1)
          cout<<"No Path exist"<<endl;
     else
     {
          shortest_path(from,P[to_i],n);
          cout<<"-->"<<to_i;
     }

}
int main()
{
    long long n,i,j,ans;
    cout<<"Enter the no. of nodes in the graph"<<endl;
    cin>>n;
    cout<<"Enter the adjacency matrix "<<endl;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
               cin>>adj[i][j];
    cout<<"Enter the value of the nodes in the graph"<<endl;
    for(i=1;i<=n;i++)
         cin>>value[i];
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
              long long val,from,to;
              case 1:
                   cout<<"Enter the node from where u want to start DFS traversal"<<endl;
                   cin>>val;
                   dfs(val,n);
                   cout<<endl;
                   break;
              case 2:
                   cout<<"Enter the node from where u want to start BFS raversal"<<endl;
                   cin>>val;
                   bfs(val,n);
                   cout<<endl;
                   break;
              case 3:
                   cout<<"Enter the two vertex between which u want the shortest path"<<endl;
                   cin>>from>>to;
                   bfs(from,n);
                   shortest_path(from,to,n);
                   cout<<endl;
                   break;
        }
    }while(ans!=4);

    return 0;
}
