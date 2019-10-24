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
			int vio=(x[0]=='v')+(x[1]=='i')+(x[2]=='o')+(x[3]=='l')+(x[4]=='e')+(x[5]=='t');

			int ind=(x[0]=='i')+(x[1]=='n')+(x[2]=='d')+(x[3]=='i')+(x[4]=='g')+(x[5]=='o');

			int yel=(x[0]=='y')+(x[1]=='e')+(x[2]=='l')+(x[3]=='l')+(x[4]=='o')+(x[5]=='w');

			int orn=(x[0]=='o')+(x[1]=='r')+(x[2]=='a')+(x[3]=='n')+(x[4]=='g')+(x[5]=='e');

			if(vio>=5)
			{
				cout<<"violet"<<endl;
				continue;
			}

			else if(ind>=5)
			{
				cout<<"indigo"<<endl;
				continue;
			}

			else if(yel>=5)
			{
				cout<<"yellow"<<endl;
				continue;
			}

			else if(orn>=5)
			{
				cout<<"orange"<<endl;
				continue;
			}



		}

	}

	return 0;
}
