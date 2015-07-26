/*Lucky numbers are subset of integers. Rather than going into much theory, let us see the process of arriving at lucky numbers,

Take the set of integers
1,2,3,4,5,6,7,8,9,10,11,12,14,15,16,17,18,19,……

First, delete every second number, we get following reduced set.
1,3,5,7,9,11,13,15,17,19,…………

Now, delete every third number, we get
1, 3, 7, 9, 13, 15, 19,….….

Continue this process indefinitely……
Any number that does NOT get deleted due to above process is called “lucky”.

Therefore, set of lucky numbers is 1, 3, 7, 13,………

Now, given an integer ‘n’, write a function to say whether this number is lucky or not.
*/
#include<iostream>
#include<stdio.h>
using namespace std;
bool isLucky(long long n)
{
    long long counter=2,next_position=n;
    while(1)
    {
        if(n<counter)
            return true;
        if(next_position%counter==0)
            return false;

        next_position=next_position-next_position/counter;
        counter++;
    }
}
int main()
{
    for(int i=1;i<=50;i++)
        if(isLucky(i))
            cout<<i<<" is Lucky"<<endl;
    return 0;
}
