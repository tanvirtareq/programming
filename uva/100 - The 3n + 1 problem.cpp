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
    for(long long i=1;i<=1000000;i++)
    {
//        cout<<i<<" "<<rec(i)<<endl;
        ar[i]=rec(i);
//        cout<<i<<" "<<ar[i]<<endl;

    }
    long long i, j;

    while(cin>>i>>j)
    {
//        if(i>j) swap(i, j);

        long long mx=0;
        for(long long l=min(i, j);l<=max(i, j);l++)
        {
//            cout<<ar[i]
            mx=max(mx, ar[l]);
        }
        cout<<i<<" "<<j<<" "<<mx<<endl;

    }




}

