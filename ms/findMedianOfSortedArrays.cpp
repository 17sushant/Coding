#include<iostream>
#define MAX(a,b) (( (a)>(b) )?(a):(b) )
#define MIN(a,b) (( (a)<(b) )?(a):(b) )
using namespace std;
int A[100],B[100];
int Median(int *A, int st, int end)
{
    int n=end-st+1;
    if(n%2==0)
        return((A[st + n/2 -1] + A[st + n/2])/2);
    else
        return(A[st + n/2]);
}
float findMedian_O_n(int n)
{
    int x=0,y=0,i=0;
    float a,b;
    while(i<=n)
    {
        i++;
        if(A[x]<B[y])
        {
            x++;
            if(i==n)
                a=A[x-1];
            if(i==n+1)
                b=A[x-1];
        }
        else
        {
            y++;
            if(i==n)
                a=B[y-1];
            if(i==n+1)
                b=B[y-1];
        }
    }
    return ((a+b)/2);
}
int findMedian_O_logn(int st1, int end1, int st2, int end2)
{
    int m1,m2;
    int n=end1-st1+1;
    if(n==0)
        return -1;
    if (n==1)
        return( (A[st1]+B[st2])/2);
    if(n==2)
        return ((MAX(A[st1],B[st2]) + MIN(A[end1],B[end2]))/2);

    m1=Median(A,st1,end1);
    m2=Median(B,st2,end2);

    if(m1>m2)
        findMedian_O_logn(st1,st1+n/2,st2+n/2 -1,end2);
    else
        findMedian_O_logn(st1+n/2 -1,end1,st2,st2+n/2);
}
int main()
{
    //A={1,4,7,7,12,15,19,24,28,30};
    //B={2,4,5,6,8,9,13,17,18,40};
    A={1, 12, 15, 26, 38};
    B = {2, 13, 17, 30, 45};
    cout<<findMedian_O_n(9)<<endl;
    cout<<findMedian_O_logn(0,9,0,9)<<endl;
    return 0;
}
