#include<bits/stdc++.h>
#define f(i, n) for(int i=1;i<=n;i++)
#define pb(a) push_back(a) 

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef pair<int, int> ii;



int main()
{

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	while(n--)
	{

		string x, y;
		cin>>x>>y;

		if(x[0]!=y[0])
		{
			cout<<"NO"<<endl;
			continue;
		}

		int fl=0;

		int i=1, j=1;

		while(i<x.size())
		{
			if(x[i]==y[j])
			{
				i++;
				j++;
			}
			else if(y[j]==y[j-1]) j++;

			else 
			{
				fl=1;
				break;
			}
		}
		while(j<y.size())
		{
			if(y[j]!=y[j-1])
			{
				fl=1;
				break;
			}
			j++;
		}

		if(fl==1) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}


	return 0;
}

