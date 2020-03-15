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

    int n, ct=0;
    cin>>n;

    int vis[n+10]={0}, a[n+10], b[n+10];

    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++) cin>>b[i];

    int j=1;
// cout<<vis[1]<<endl;
    for(int i=1;i<=n;)
    {
        // cout<<i<<" "<<j<<endl;
        if(b[i]==a[j])
        {
            j++;
            i++;
            // cout<<"1"<<endl;
        }

        else if(vis[a[j]]==0)
        {
            ct++;
            // cout<<i<<" "<<j<<endl;
            // cout<<ct<<endl;
            // cout<<2<<endl;
            vis[b[i]]=1;
            i++;
        }
        else j++;
    }

    cout<<ct<<endl;

	return 0;
}
