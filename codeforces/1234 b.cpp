#include<bits/stdc++.h>

#define dbg(a) cout<<#a<<" ="<<a<<endl
#define pb push_back
#define mk make_pair
#define md 1000000007

using namespace std;

typedef long long ll;
typedef long long unsigned lu;

map<ll, ll> mp;


int main()
{
//	#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	#endif

	ll n, k;
	cin>>n>>k;

	queue<ll> q;
//	queue<ll>:: iterator it;

	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(mp[x]==0)
        {
            mp[x]=1;
            q.push(x);

        }

        if(q.size()>k)
        {

            ll fc=q.front();
            q.pop();
            mp[fc]=0;
        }

	}

	vector<ll> v;


	while(!q.empty())
	{
		ll x=q.front();
		q.pop();
		v.push_back(x);
	}

	reverse(v.begin(), v.end());

	cout<<v.size()<<endl;

	for(int i=0;i<v.size();i++)
    {

        cout<<v[i]<<" ";
    }

	return 0;
}
