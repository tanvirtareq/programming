#include<bits/stdc++.h>


#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define dbg(a) cout<<#a<<" = "<<a<<endl
#define MX  11010

using namespace std;

typedef long long lu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;

lu fact[MX];
lu md=10000000000007;

lu c[MX][MX];

lu binomialCoeff(lu n, lu k)
{
    lu i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j - 1]%md +
                          c[i - 1][j]%md)%md;
        }
    }
    return c[n][k];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0]=1;
    fact[1]=1;

    for(lu i=2;i<MX;i++)
    {
        fact[i]=((fact[i-1]%md)*(i%md))%md;
    }
    binomialCoeff(MX-1, MX-1);
    lu t;
    cin>>t;
    for(lu in=1;in<=t;in++)
    {
        lu l, m, n;
        cin>>l>>m>>n;
        l=l*l;
        lu ans=0;
        for(lu i=m;i<=n;i++)
        {
            lu y=c[l][i]%md;
            lu x=(y*(fact[i]%md))%md;
            ans=(ans+x)%md;
        }
        cout<<"Case "<<in<<": "<<ans<<endl;
    }
	return 0;
}

/**
 C(n, k) = C(n-1, k-1) + C(n-1, k)
   C(n, 0) = C(n, n) = 1

*/



