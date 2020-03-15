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

	while(n--)
	{
		string x;
		cin>>x;

		if(x.size()==3)
		{
			cout<<"red"<<endl;
		}
		else if(x.size()==4)
		{
			cout<<"blue"<<endl;
		}

		else if(x.size()==5)
		{
			cout<<"green"<<endl;
			continue;
		}

		else 
		{
			int a=x[0];
			int b=x[1];
			int c=x[2];

			int vlt=0;
			if(x[0]=='v')
			{
				vlt++;
			}

			if(x[1]=='i')
			{
				vlt++;
			}
			if(x[2]=='o')
			{
				vlt++;
			}

			if(vlt>=2)
			{
				cout<<"violet"<<endl;
				continue;
			}

			vlt=0;
			if(x[0]=='i')
			{
				vlt++;
			}

			if(x[1]=='n')
			{
				vlt++;
			}
			if(x[2]=='d')
			{
				vlt++;
			}

			if(vlt>=2)
			{
				cout<<"indigo"<<endl;
				continue;
			}

			vlt=0;
			if(x[0]=='y')
			{
				vlt++;
			}

			if(x[1]=='e')
			{
				vlt++;
			}
			if(x[2]=='l')
			{
				vlt++;
			}

			if(vlt>=2)
			{
				cout<<"yellow"<<endl;
				continue;
			}

			vlt=0;
			if(x[0]=='o')
			{
				vlt++;
			}

			if(x[1]=='r')
			{
				vlt++;
			}
			if(x[2]=='n')
			{
				vlt++;
			}

			if(vlt>=2)
			{
				cout<<"orange"<<endl;
				continue;
			}



		}

	}

	return 0;
}
