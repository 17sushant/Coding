#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
char *smallest_largest_string(char **arr,int n, char **ans1)
{
    char *largest,*smallest;
    if(strcmp(*(arr+0),*(arr+1))>0)
    {
        largest=*(arr+0);
        smallest=*(arr+1);
    }
    int i;
    for(i=2;i<n-1;i+=2)
    {
        if(strcmp(*(arr+i+0),*(arr+i+1))>0)
        {
            if(strcmp(largest,*(arr+i+0))<0)
                largest=*(arr+i+0);
            if(strcmp(smallest,*(arr+i+1))>0)
                smallest=*(arr+i+1);
        }
        else
        {
            if(strcmp(largest,*(arr+i+1))<0)
                largest=*(arr+i+1);
            if(strcmp(smallest,*(arr+i+0))>0)
                smallest=*(arr+i+0);
        }
    }
    if(n%2!=0)
    {
        if(strcmp(largest,*(arr+i))<0)
        {
            largest=*(arr+i);
        }
        if(strcmp(smallest,*(arr+i))>0)
        {
            smallest=*(arr+i);
        }
    }
    *ans1=largest;
    return(smallest);

}
int main()
{
    char *arr[100];
    arr={"sushant","raj","nitant","samnt","sourabh","anpnd","anirudh","anirudha","anuradha",
         "sushantraj","susioo","annre","sadasd","ewrwerw","ewrwrw"};
    int n=15;
    char *ans1;
    char *smallest=smallest_largest_string(arr,n,&ans1);
    char *largest=ans1;
    cout<<largest<<endl<<smallest<<endl<<endl;
    return 0;
}
