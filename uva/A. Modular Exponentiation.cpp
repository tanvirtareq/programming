#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

int power(int b, int p)
{
    if(p==0) return 1;
    if(p==1) return b;

    if(p%2==0)
    {
        int x=power(b, p/2);
        return x*x;
    }
    else
    {
        int x=power(b, p/2);
        return b*x*x;
    }
}

int main()
{
   // cout<<power(2, 3)<<endl;

    int n, m;
    cin>>n>>m;

    if(n>26)
        cout<<m<<endl;

    else
    {
        int x=power(2, n);
        cout<<m%x<<endl;
    }
	return 0;
}



