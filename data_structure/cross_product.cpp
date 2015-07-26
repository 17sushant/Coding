#include<iostream>
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
using namespace std;

struct point
{
    float x,y;
};
float cross_product(point p0,point p1,point p2)
{
    return( (p2.x-p0.x)*(p1.y-p0.y) - (p1.x-p0.x)*(p2.y-p0.y));
}
int main()
{
    point p[3];
    while(true)
    {
        cout<<"enter the coordinates of three points"<<endl;
    for(int i=0;i<3;i++)
        cin>>p[i].x>>p[i].y;
    if(cross_product(p[0],p[1],p[2]) > 0)
        cout<<"right turn"<<endl;
    else if(cross_product(p[0],p[1],p[2]) == 0)
        cout<<"no turn"<<endl;
    else
        cout<<"left turn"<<endl;
    }

    return 0;
}
