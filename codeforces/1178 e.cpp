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

	string s;


	string a1, a2;
	cin>>s;
	int n=s.size()-1;

	int i=0;
	int j=n;

	while(i<j)
	{
		if(s[i]==s[j])
		{
			a1.push_back(s[i]);
			i++;
			j--;
			
			// cout<<a1<<endl;

		}
		else if(s[i+1]==s[j])
		{
			i++;
		}
		else if(s[i]==s[j-1])
		{
			j--;
		}
		else 
		{
			i++;
			j--;
		}

	}

	if(a1.size()*2+1>=s.size()/2)
	{
		cout<<a1<<s[i];
		reverse(a1.begin(), a1.end());
		cout<<a1<<endl;
	}
	else cout<<"IMPOSSIBLE"<<endl;



	return 0;
}