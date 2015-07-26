#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int arr[5][3]={{1,2,3},
                {4,5,6},
                {7,8,9},
                {10,11,12},
                {13,14,15}};
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    cout<<**arr<<" "<<**(arr+1)<<" "<<**(arr+2)<<" "<<**(arr+3)<<" "<<**(arr+4)<<endl;
    cout<<*(*arr +0)<<" "<<*(*arr + 1)<<" "<<*(*arr + 2)<<" "<<*(*arr + 3)<<" "<<*(*arr + 5)<<endl;
    cout<<*(*(arr+0) +0)<<" "<<*(*(arr+1) +1)<<" "<<*(*(arr+2) +2)<<" "<<*(*(arr+3) +1)<<endl;
    return 0;
}
