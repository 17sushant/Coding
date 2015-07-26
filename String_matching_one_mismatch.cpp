#include<iostream>
#include<stdio.h>
#include<cstring>
#define MAX 1000
using namespace std;
int main()
{
    char str[MAX],pattern[MAX];
    long long i,j,count,m,n,check;
    while(cin>>str>>pattern)
    {   //cout<<"1"<<endl;
        n=strlen(str),m=strlen(pattern);
        i=0;
        while(i<n)
        {
            cout<<"i"<<i<<endl;
            count=0;
            j=0;
            check=0;
            while(j<m)
            {

                if(str[i]==pattern[j])
                {
                    count++;
                    i++;
                    j++;

                }
                else
                {
                    if(check!=1)
                    {
                        cout<<"2"<<endl;
                        if(str[i]==pattern[j+1])
                        {
                            cout<<"3"<<endl;
                            check=1;
                            j++;
                            continue;
                        }
                        else if(str[i+1]==pattern[j])
                        {
                            cout<<"4"<<endl;
                            check=1;
                            i++;
                            continue;
                        }
                        else if(str[i+1]==pattern[j+1])
                        {
                            cout<<"5"<<endl;
                            check=1;
                            i++;j++;
                            continue;
                        }
                        else
                        {
                            cout<<"6"<<endl;
                            i++;
                            break;
                        }
                    }
                    else
                    {
                        cout<<"7"<<endl;
                        i++;
                        break;
                    }
                }
            }
            cout<<"count "<<count<<endl;
            if(count==m)
            {
                cout<<"Complete Matching found at index "<<i-m<<endl;
                break;
            }
            else if(count==m-1)
            {
                cout<<"Matching found with 1 error only"<<endl;
                break;
            }
        }
    }
    return 0;
}
