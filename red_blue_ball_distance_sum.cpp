#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<map>
#include<math.h>
using namespace std;
struct ball
{
       int num;
       char color;
};
int main()
{
    map<int,int> processed;
    int n,total_dist_sum=0,i,j;
    cout<<"Enter total no of each balls"<<endl;
    cin>>n;
    struct ball balls[2*n];
    for(i=1;i<=2*n;i++)
        cin>>balls[i].color>>balls[i].num;
    for(i=1;i<=(2*n);i++)
    {
         if(processed[balls[i].num])
         {
             total_dist_sum+=abs(i-processed[balls[i].num]);
             processed.erase(balls[i].num);
         }
         else
         {
             processed[balls[i].num]=i;
         }
    }
    cout<<"Total sum is "<<total_dist_sum<<endl;
    cin>>i;
    return 0;
}
