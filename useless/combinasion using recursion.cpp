#include<bits/stdc++.h>

using namespace std;

int c(int n, int r)
{
    if(r=0) return 1;

    if(r=n) return n;

    if(r<0||r>n) return 0;

    return c(n-1, r-1)+c(n-1, r);
}

int main()
{
    int n, r;

    while(cin>>n>>r)

    cout<<c(n,r)<<endl;


    return 0;
}
