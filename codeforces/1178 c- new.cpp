#include<bits/stdc++.h>

#define dbg cout<<"yes"<<endl;
#define v(a) vector<a>
#define p(a, b) pair<a,b> 
#define md 998244353

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef priority_queue<ll> pqi;
typedef priority_queue<ll , vi, greater<ll> > mnpqi;

#define sz 2010

bool chk[sz+5];
vector<int> prime;



void seive()
{
    chk[1]=1;

    for(int i=3;i*i<=sz;i+=2)
    {
    	// cout<<i<<endl;
        if(chk[i]==0) {

        for(int j=i+i;j<=sz;j+=i){
            chk[j]=1;
        
        // if(j==8) dbg;
    }

        }
    }



    // for(int i=3;i<=sz;i+=2)
    // {
    //     if(chk[i]==0){
    //         prime.push_back(i);
    //     }
    // }

   // cout<< prime[0] <<endl;
    return ;


}

bool isp(int n)
{
	if(n%2==0) return 0;

	else return !chk[n];
}

int main()
{
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	seive();


	int n;
	cin>>n;
	int nxtp;


	for(int i=0;;i++)
	{
		if(isp(n+i))
		{
			nxtp=i;
			// cout<<i<<endl;
			break;
		}
	}
	cout<<nxtp+n<<endl;

	for(int i=1;i<n;i++)
	{
		cout<<i<<" "<<i+1<<endl;
	}
	cout<<n<<" "<<1<<endl;

	int vis[n+10]={0};

	for(int i=1;nxtp;i++)
	{
		if(vis[i]==0 && vis[i+2]==0){
		cout<<i<<" "<<(i+2)%n<<endl;
		vis[i]=1;
		vis[i+2]=1;
		nxtp--;
	}
	}
	

	return 0;
}