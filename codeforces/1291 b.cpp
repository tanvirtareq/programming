#include<bits/stdc++.h>



#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define dbg(a) cput<<#a<<" = "<<a<<endl

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;

int slvl(vector<ll> &v)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]<i) return i;
    }
    return v.size();

}

int slvr(vector<ll> &v)
{
    reverse(v.begin(), v.end());
    for(int i=0;i<v.size();i++)
    {
        if(v[i]<i) return i;
    }
    return v.size();

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> v;
        for(int i=1;i<=n;i++)
        {
            ll x;
            cin>>x;
            v.push_back(x);
        }
        ll l=slvl(v);
        ll r=slvr(v);
        if(l+r>v.size()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
//        if(slv1(v)) cout<<"Yes"<<endl;
//        else if(slv2(v)) cout<<"Yes"<<endl;
//        else cout<<"No"<<endl;
    }

	return 0;
}


