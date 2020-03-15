#include<bits/stdc++.h>
#define mxx 100000000
#define ll long long
#define MX 70
using namespace std;

ll c[MX][MX];

ll binomialCoeff(ll n, ll k)
{
    ll i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j - 1] +
                          c[i - 1][j]);
        }
    }
    return c[n][k];
}


int main()
{
    ll t;
    cin>>t;

    binomialCoeff(60, 60);

    while(t--)
    {
        ll n;
        cin>>n;
        if(n==2)
        {
            cout<<1<<endl;
            continue;
        }
        ll x=0;
        while(n)
        {
            x++;
            n=n/2;
        }
        x--;

//        ll x=log2(n);
//        cout<<"x "<<x<<endl;

        if(x%2==1) x--;

        ll ans =0;

        while(x)
        {
            ans+=c[x-1][x/2];
            x-=2;
        }

        cout<<ans<<endl;
    }

    return 0;
}





