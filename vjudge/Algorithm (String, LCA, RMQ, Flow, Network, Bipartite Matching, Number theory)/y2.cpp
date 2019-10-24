#include<bits/stdc++.h>


#define sci(a) scanf("%d", &a)
//#define v(a) vector<a>
#define p(a, b) pair<a, b>

using namespace std;

typedef long long int ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int>, greater<int> > mnpqi;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll c;
    while(cin>>c)
    {
        if(c==0) break;

        vector<ll> v;

        for(ll y=0;y<10;y++)
        {
            ll x1=c-y;
            if(x1>0 and x1%9==0)
            {
                ll x=x1/9;
                v.push_back(10*x+y);
            }
        }

        sort(v.begin(), v.end());

        cout<<v[0];
        for(ll i=1;i<v.size();i++)
        {
            cout<<" "<<v[i];
        }
        cout<<endl;

    }

    return 0;
}

