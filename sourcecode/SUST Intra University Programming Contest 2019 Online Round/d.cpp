#include<bits/stdc++.h>

#define f(i, n) for(int i=1;i<=n;i++)
#define sci(a) scanf("%d", &a)
#define wi(a) printf("%d\n", a)
#define dbg printf("yes\n")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> ii;
typedef priority_queue<int> pqi;
typedef priority_queue<int , vector<int> , greater<int> > mnpqi;


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int n;
	cin>>n;

	int ar[n+10];
	queue<int> q;
	f(i, n)
	{
		cin>>ar[i];
		q.push(ar[i]);
	}

	

	// for(int i=;i>=1;i--)
	// {
	// 	q.push(ar[i]);
	// }

	int dl=1;

	int ct=0;

	int pvct=ct;

	while(!q.empty())
	{
		ct++;

		cout<<ct<<" "<<q.front()<<endl;
		if(q.front()==dl)
		{
			q.pop();
			cout<<dl<<" "<<ct-pvct<<endl;
			pvct=ct;
			dl++;

		}
		else 
		{
			int tmp=q.front();
			q.pop();
			q.push(tmp);
		}

	}

	cout<<ct<<endl;

	return 0;
}
