#include<bits/stdc++.h>

using namespace std;

long long rec(long long x)
{
    long long ct=1;

    while(x!=1)
    {
        ct++;
        if(x%2==0)
        {
            x=x/2;
        }
        else x=3*x+1;

    }
    return ct;

}

long long ar[1000100];

int main()
{
    long long i, j;

    while(cin>>i>>j)
    {
        cout<<abs(i-j)<<endl;
    }




}


