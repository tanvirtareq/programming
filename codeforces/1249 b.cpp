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
    while(q--)
    {
        ll n;
        cin>>n;

        vector<int> v[200100];

        for(int i=1;i<=n;i++)
        {
            ll x;
            cin>>x;
            v[i].push_back(x);
        }

        int vis[200010]={0};

        for(int i=1;i<=n;i++)
        {
            if(vis[i]!=0) continue;

            queue<int> q;

            vis[i]=1;
            int rt=i;

            int j=i;

            int ct=1;
            j=v[j][0];

            while(j!=rt)
            {
                vis[j]=1;
                ct++;
                j=v[j][0];
            }

            j=i;
            vis[i]=ct;
            j=v[j][0];
            while(j!=rt)
            {
                vis[j]=ct;
                j=v[j][0];
            }

        }

        for(int i=1;i<=n;i++) cout<<vis[i]<<" ";

        cout<<endl;
    }



	return 0;
}
