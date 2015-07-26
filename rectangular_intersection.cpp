#include<iostream>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<utility>
using namespace std;
int bitcode(int x1,int x2,int y1,int y2, int x,int y)
{
    int code=0;
    if(x>x2)
        code|=1;
    if(x<x1)
        code|=2;
    if(y>y2)
        code|=8;
    if(y<y1)
        code|=4;
    return code;
}
int main()
{
    int x1,x2,x3,x4,y1,y2,y3,y4,xa,xb,ya,yb,Abit,Cbit;
    cout<<"Enter bottom left and top right corner coordinates of the two rectange"<<endl;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    Abit=bitcode(x1,y1,x2,y2,x3,y3);
    Cbit=bitcode(x1,y1,x2,y2,x4,y4);
    if(Abit&8 || Cbit& 4 || Abit&1 || Cbit&2)
        cout<<"No Intersection between the two"<<endl;
    else if(Abit&6 |||Dbit&9)
        cout<<"Rectangle 2 has completely shadowed Rectange 1"<<endl<<"And the Overlapping area is "<<(x2-x1)*(y2-y1)<<endl;
    else if(Abit==0 && D==0)
        cout<<"Rectangle 1 has completely shadowed Rectange 2"<<endl<<"And the Overlapping area is "<<(x4-x3)*(y4-y3)<<endl;
    else
    {
        xa=(x3>x1?x1:x3);
        xb=(x4>x2?x2:x4);
        ya=(y3>y1?y1:y3);
        yb=(y4>y2?y2:y4);
        cout<<"Intersection Area is "<<(xb-xa)*(yb-ya)<<endl;
    }
    return 0;
}
