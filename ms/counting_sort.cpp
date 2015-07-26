#include<iostream>
using namespace std;
void cs(int arr[], int n, int k)
{
     int temp[k+1],i,c;
     for(i=0;i<=k;i++)
          temp[i]=0;
     for(i=1;i<=n;i++)
          temp[arr[i]]++;
     for(i=1;i<=k;i++)
     {
          c=temp[i];
          temp[i]+=temp[i-1];
          while(c>0)
          {
                 //cout<<"asdaD "<<i<<"c "<<c<<"temp[i] "<<temp[i]<<" "<<"[] "<<(temp[i]-c+1);;
                 arr[temp[i]- c-- +1]=i;
          }
     }
}
int main()
{
    int n,k,arr[100];
    cout<<"enter n"<<endl;
    //cin>>n;
    n=12;
    cout<<"enter k(k<n)"<<endl;
    //cin>>k;
    k=5;
    cout<<"enter n elements of array"<<endl;
    for(int i=1;i<=n;i++)
            arr[i]=(i%(k+1)==0?1:i%(k+1));
            //cin>>arr[i];
    cs(arr,n,k);
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    //getchar();
    return 0;
}
