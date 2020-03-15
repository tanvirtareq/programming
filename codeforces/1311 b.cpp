#include<bits/stdc++.h>


#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define dbg(a) cout<<#a<<" = "<<a<<endl

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;

ll c[1000];
vector<pair<ll, ll> > v;
vector<ll> g[1000];

void dfs(int u, int cl)
{
    c[u]=cl;
//    dbg(u);
    for(int i=0;i<g[u].size();i++)
    {
        if(c[g[u][i]]!=0) continue;
        dfs(g[u][i], cl);
    }
    return;
}

int cmp(pair<ll, ll> p, pair<ll, ll> q)
{
    if(p.first==q.first) return p.second<q.second;
    return p.first<q.first;

}

int sort(int st, int ed)
{
    if(ed-st==1)
    {
        if()
    }

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        ll m, n;
        cin>>m>>n;
        vector<int> v;
        v.resize(m);
        for(auto &it:v)
            cin>>it;

        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            mp[x]=1;
        }

        if(sort(0, m-1)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

	return 0;
}


