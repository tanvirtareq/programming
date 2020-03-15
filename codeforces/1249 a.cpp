#include<bits/stdc++.h>



#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define dbg(a) cout<<#a<<"= "<<a<<endl;

using namespace std;

typedef long long int ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll q;
    cin>>q;
    // cout<<q<<endl;

    while(q--)
    {
        ll n;
        vector<int> v;
        cin>>n;

        for(int i=1;i<=n;i++)
        {
            ll x;
            cin>>x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());

        ll f=0;

        for(int i=1;i<v.size();i++)
        {
            if(abs(v[i]-v[i-1])==1) f=1;
        }

        if(f==1) cout<<2<<endl;
        else cout<<1<<endl;

    }



	return 0;
}
