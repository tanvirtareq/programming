
#include<bits/stdc++.h>


#define sci(a) scanf("%d", &a)
#define v(a) vector<a>
#define p(a, b) pair<a, b>

using namespace std;

typedef long long int li;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;

int n, l, r, t;
bool vis[10001000];

int rec(int st, int tk)
{
    if(st==t) return tk;

    if(st<=0 or st>n) return INT_MAX;

    if(vis[st]==1) return INT_MAX;
    vis[st]=1;

    int p=rec(st+l, tk+1);
    int q=rec(st-r, tk+1);

    return min(p, q);

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin>>c;

    while(c--)
    {
        memset(vis, 0, sizeof vis);
        cin>>n>>r>>l>>t;

        if(t%__gcd(l, r)!=0)
        {
            cout<<"uh-oh!"<<endl;
            continue;
        }

        if(t==1){
            cout<<0<<endl;
            continue;
        }

        vis[1]=1;

        int x=rec(1+l, 1);

        if(x==INT_MAX) cout<<"uh-oh!"<<endl;

        else{
            cout<<x<<endl;

        }

    }

	return 0;
}
