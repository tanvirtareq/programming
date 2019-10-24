#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pi 2*acos(0.0)
#define Mk make_pair
#define Pb push_back
#define sp " "
#define fst first
#define snd second
int i,j,k;
int fr[]={0,0,1,-1,-1,1,-1,1};
int fc[]={-1,1,0,0,1,1,-1,-1};

int main()
{
	ios_base::sync_with_stdio(false);
	ll tc;
	cin>>tc;
	for(i=1 ; i<=tc ; i++)
	{
		string s,sb,sr;
		vector<int> v;
		cin>>s;
		sb = sr = s;
		ll a=0 ,b =0 ,c = 0,cnt=0,lnth = s.length();
		for(j=0 ; j<lnth ; j++)
		{
			if(s[j] =='^')
			{
				sb[j] = '(';
				sr[lnth-j-1] = ')';
			}
			else if( s[j] == '_')
				sb[j] = sr[lnth-j-1] = '_';
		}
		lnth = sb.length();
		for(j=0 ; j< lnth ; j++)
		{
			if(sb[j] == '(') a++;
			else if(sb[j] == '_' && b<a) b++;
			else if(sb[j] == ')' && a>0 && b>0)
			{
				cnt++;
				a--;
				b--;
			}
		}
		for(j=0 ; j< lnth ; j++)
		{
			if(sr[j] == '(') a++;
			else if(sr[j] == '_' && b<a) b++;
			else if(sr[j] == ')' && a>0 && b>0)
			{
				cnt++;
				a--;
				b--;
			}
			cout<<sr[j];
		}
		ll x = cnt/2;
		cout<<"Case "<<i<<": "<<x<<endl;

	}
	return 0;
}

///_^^_^^___^^^_^^^^^_^^^^^^^^_^_^_^___^___^^^^^_
