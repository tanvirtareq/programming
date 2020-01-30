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
ll n, d;
ll Ceil(ll a, ll b)
{
    return a/b+(a%b>0);
}
int chk(ll a, ll b)
{
    for(ll i=a;i<=b;i++)
    {
        if(i+Ceil(d, i+1)<=n) return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {

        cin>>n>>d;
        int f=0;
        if(d<=n) f=1;
        for(ll i=1;i*i<=d;i++)
        {
            if(i+Ceil(d, i+1)<=n)
            {
                f=1;
                break;
            }
        }
        if(f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
	return 0;
}

