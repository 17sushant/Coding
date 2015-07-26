#include<iostream>
#include<conio.h>
using namespace std;
long long arr[100][100];
void flood_fill(long long s_i,long long s_j,long long t_i,long long t_j,long long n)
{
     if(s_i==t_i && s_j==t_j)
          return;
     long long r[4]={1,-1,0,0};
     long long c[4]={0,0,1,-1};
     long long i;
     for(i=0;i<4;i++)
     {    
           long long x,y;
           x=s_i+r[i];
           y=s_j+c[i];
           if(x>0 && x<=n && y>0 && y<=n && arr[x][y]!=-1)
           {
                if(arr[x][y]>arr[s_i][s_j]+1)
                {     
                      arr[x][y]=arr[s_i][s_j]+1;
                      flood_fill(x,y,t_i,t_j,n);
                }   
           }
     }
}
void flood_fill_path(long long a,long long b,long long n)
{
     long long r[4]={1,-1,0,0};
     long long c[4]={0,0,1,-1};
     long long i;
     for(i=0;i<4;i++)
     {    
           long long x,y;
           x=a+r[i];
           y=b+c[i];
           if(x>0 && x<=n && y>0 && y<=n && arr[x][y]==(arr[a][b]-1))
           {
                flood_fill_path(x,y,n);
                cout<<"-->("<<a<<","<<b<<") ";
                break;
           }
     }
}
int main()
{
    long long n,s_i,s_j,t_i,t_j,i,j,x;
    cout<<"Enter n"<<endl;
    cin>>n;
    cout<<"Enter the array"<<endl;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           cin>>arr[i][j];
    cout<<"Enter the starting point and finishing point coordinates"<<endl;
    cin>>s_i>>s_j>>t_i>>t_j;
    //flood fill
    arr[s_i][s_j]=0;
    flood_fill(s_i,s_j,t_i,t_j,n);
    x=arr[t_i][t_j];
    cout<<"The minimum distance is "<<x<<endl;
    /*for(i=1;i<=n;i++){
       for(j=1;j<=n;j++)
           cout<<arr[i][j]<<" ";
           cout<<endl;}*/
    cout<<"The minimum path : "<<endl;
    flood_fill_path(t_i,t_j,n);
cin>>i;
    return 0;
}
