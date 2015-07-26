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
#define MAX 100
using namespace std;
struct point
{
    float x,y;
};
float cross_product(point p0,point p1,point p2)
{
    return( (p2.x-p0.x)*(p1.y-p0.y) - (p1.x-p0.x)*(p2.y-p0.y));
}

//graham scan algorithm for solving convex hull....
int main()
{
    long long n;
    while(cin>>n)
    {

        stack<point> st;
        point p[MAX];
        long long i,j;//,check[MAX];
        float angle[MAX];
        //cout<<"enter n"<<endl;

        //cout<<"enter the coordinates of the points"<<endl;
        for(i=0;i<n;i++)
        {
            cin>>p[i].x>>p[i].y;
            //check[i]=1;
        }
        for(i=0;i<n;i++)
        {
            if(p[i].y==p[0].y)
                if(p[i].x<p[0].x)
                {
                    point tem=p[0];
                    p[0]=p[i];
                    p[i]=tem;
                }
            if(p[i].y<p[0].y)
            {
                point tem=p[0];
                p[0]=p[i];
                p[i]=tem;
            }
        }
        for(i=1;i<n;i++)
        {
            if((p[i].x-p[0].x)==0)
                angle[i]=PI/2;
            else
            {
                float f=(float)(p[i].y - p[0].y)/(float)(p[i].x - p[0].x);
                if(f<0)
                {
                    angle[i]=atan(-1*f);
                    angle[i]=PI-angle[i];
                }
                else
                    angle[i]=atan(f);
            }
        }
        for(i=1;i<n;i++)                //angle of p[0] is not defined...
        {
            for(j=i+1;j<n;j++)
            {
                if(angle[j]==angle[i])
                {
                    float di=(p[i].x-p[0].x)*(p[i].x-p[0].x) + (p[i].y-p[0].y)*(p[i].y-p[0].y);
                    float dj=(p[j].x-p[0].x)*(p[j].x-p[0].x) + (p[j].y-p[0].y)*(p[j].y-p[0].y);

                    if( dj < di)
                    {
                        point temp=p[i];
                        p[i]=p[j];
                        p[j]=temp;

                        float ang=angle[i];
                        angle[i]=angle[j];
                        angle[j]=ang;
                    }
                }
                if(angle[j]<angle[i])
                {
                    point temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;

                    float ang=angle[i];
                    angle[i]=angle[j];
                    angle[j]=ang;
                }
            }
        }
        /*for(i=0;i<n;i++)
        {
            cout<<p[i].x<<" "<<p[i].y<<" "<<angle[i]<<endl;
        }*/
        st.push(p[0]);
        st.push(p[1]);
        st.push(p[2]);

        for(i=3;i<n;i++)
        {
            point top,second_top,a;
            top=st.top();
            st.pop();
            second_top=st.top();
            st.push(top);
            while(st.size()>=3 && cross_product(second_top,top,p[i])>=0)
            {
                st.pop();

                top=st.top();
                st.pop();
                second_top=st.top();
                st.push(top);
            }
            st.push(p[i]);
        }
        cout<<"convex hull vertices"<<endl;
        while(!st.empty())
        {
            cout<<st.top().x<<" "<<st.top().y<<endl;
            st.pop();
        }
        cout<<endl;
    }
    return 0;
}
