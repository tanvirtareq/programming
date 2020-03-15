#include<bits/stdc++.h>

using namespace std;

typedef long long int llu;

llu bigmodf(llu b, llu p, llu m)
{
    if(p==0) return 1;
    else if(p==1) return b%m;

    else if(p%2==0)
    {

        llu x=bigmodf(b, p/2, m);

        return (x*x)%m;
    }

    else
    {
        llu x=bigmodf(b, (p-1)/2, m);
        return ((b%m)*x*x)%m;
    }

}


int func(int a)
{
    int mod=1;
    int cnt=1;

    while(mod%a!=0)
    {
        mod=(bigmodf(10, cnt, a)+mod%a)%a;
        cnt++;
    }

    return cnt;

}

int main()
{
    int a;
    while(cin>>a)
    {
        long long unsigned cnt=1;

        string s;

        cnt=func(a);
        cout<<cnt<<endl<<s;
    }

    return 0;
}
