#include<iostream>
#include<stack>
using namespace std;
long long P[100];
long long dijkstra_short_value(long long w[][100],long long adj[][100],long long from, long long to,long long n)
{
      long long dist[n+1],Q[n+1],check[n+1],x=0,i,v;
      for(i=1;i<=n;i++)
      {
           P[i]=-1;
           dist[i]=999999999;                 
           check[i]=0;
           Q[i]=i;
      }
      dist[from]=0;
      P[from]=-1;
      while(x<n)
      {
           long long u,min=999999999;
           for(i=1;i<=n;i++)
                 if(check[i]==0)
                 {       
                         u=i;
                         break;
                 }
           for(i=1;i<=n;i++)
           {
                if(check[i]==0)
                {
                    if(dist[i]<min)
                    {
                         min=dist[i];
                         u=i;               
                    }
                }
                
           }          
           check[u]=1;
           x++;
           //cout<<"u "<<u<<endl;
          // cout<<"x "<<x<<endl;
           if(dist[u]==999999999)           // all remaining vertices are inaccessible from source
                break;
           for(v=1;v<=n;v++)
           {
                long long min_w;
                if(adj[u][v]==1 && check[v]==0) 
                {
                     min_w=dist[u] + w[u][v];
                     //cout<<endl<<"v "<<v<<endl<<endl;
                     if(min_w<dist[v])
                     {       
                            dist[v]=min_w;
                            P[v]=u;       
                     }
                }
                //cout<<"v minimum "<<v<<endl;                 
                //cout<<"dist[v] "<<dist[v]<<endl;
           }
      }
      /*for(i=1;i<=n;i++)
            cout<<dist[i]<<" ";
      cout<<endl;*/
      return dist[to];
}
void dijkstra_path(long long from, long long to)
{
     long long u;
     stack<long long> st;
     u=to;
     while(P[u]!=-1)
     {
          st.push(u);
          u=P[u];               
     }
     while(!st.empty())
     {
          cout<<st.top()<<"-->";
          st.pop();
     }
}
int main()
{
    long long adj[100][100],i,j,w[100][100],n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    cout<<"Enter the adjacency matrix of the weighted graph"<<endl;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
            cin>>adj[i][j];
    cout<<"Enter the weights of the graph"<<endl;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
            cin>>w[i][j];
    long long from,to;
    while(1)
    {
          //cout<<"Enter the 2 node numbers between which u want the shortest path"<<endl;
          cin>>from>>to;
          cout<<"Shortest path value is "<<dijkstra_short_value(w,adj,from,to,n)<<endl; 
          cout<<"Shortest path traversal is "<<endl;
          dijkstra_path(from,to);
          cout<<endl;
    }
    return 0;
}
