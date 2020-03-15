#include<bits/stdc++.h>
#define f(i, n) for(ll i=1;i<=n;i++)
#define clr(a) memset(a, 0, sizeof a)

 
using namespace std;
 
typedef long long ll;
typedef long long unsigned lu;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef priority_queue<ll> pq;
typedef priority_queue<ll, vector<ll>, ll> mnpq;

/// for seive prime

#define sz 2850131

bool chk[sz+5];
vector<int> prime;

void seive()
{
    prime.push_back(2);

    for(int i=3;i*i<=sz;i+=2)
    {
        if(chk[i]==0) {

        for(int j=i+i;j<=sz;j+=i)
            chk[j]=1;

        }
    }


    for(int i=3;i<=sz;i+=2)
    {
        if(chk[i]==0){
            prime.push_back(i);
        }
    }

   // cout<< prime[0] <<endl;


}

bool isp(int x)
{
	if(x==2) return 1;
	if(x%2==0) return 0;
	if(chk[x]==0) return 1;
	return 0;
}

 
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	seive();

	int n;
	cin>>n;

	map<int, int> mp;
	map<int, int>::iterator it;

	f(i, 2*n)
	{
		int x;
		cin>>x;
		mp[x]++;
		// cout<<x<<endl;
	} 

	// for(it =mp.begin();it!=mp.end();it++)
	// {
	// 	cout<<it->first<<" "<<it->second<<endl;
	// }

	for(it=mp.end(), it--;; it--)
	{
		int x=it->first;
		if(mp[x]<=0) continue;

		for(int i=0;prime[i]*prime[i]<=x;i++)
		{
			if(x%prime[i]==0)
			{
				mp[x/prime[i]]--;
				break;
			}
		}

		if(it==mp.begin()) break;
	}

	// for(it =mp.begin();it!=mp.end();it++)
	// {
	// 	cout<<it->first<<" "<<it->second<<endl;
	// }

	for(it=mp.begin();it!=mp.end();it++)
	{
		int x=it->first;
		if(mp[x]<=0 || !isp(x)) continue;

		int p=prime[x-1];
		// cout<<x<<" "<<p<<endl;
		if(mp[p]>0) mp[p]--;
	}
	for(it =mp.begin();it!=mp.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}

	for(it =mp.begin();it!=mp.end();it++)
	{
		int x=it->first;

		f(i, mp[x])
		{
			cout<<x<<" ";
		}
	}


	return 0;
}