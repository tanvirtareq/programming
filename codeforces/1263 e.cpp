#include<bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n , mx=0, r=0,j=1, l=0;
	cin>>n;
	cin.ignore();
	char str[n+10];
	memset(str, 0, sizeof str);
	// stack<char> spr, spst;
	int spri=0, spsti=0;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		if(ch=='R')
		{
			if(str[j]=='(') spri++;
			if(str[j]==')') spri--;
			mx=max(mx, (int)max(abs(spri), abs(spsti)));
		 	j++;
		}

		else if(ch=='L' and j>1) {
			if(str[j]==')') spsti++;
			if(str[j]=='(') spsti--;

			mx=max(mx, (int)max(abs(spri), abs(spsti)));
		 	j--;
		}

		else if(ch=='(')
		{
			if(str[j]==')') r+=2;
			else if(str[j]!='(') r++;
			str[j]=ch;
		}

		else if(ch==')')
		{
			if(str[j]=='(') r-=2;
			else if(str[j]!=')') r--;
			str[j]=ch;
		}
		else {
			if(str[j]=='(') r--;
			else if(str[j]==')') r++;
			str[j]=ch;
		}

		mx=max(mx, abs(r));

		if(r==0) cout<<mx<<" ";
		else cout<<-1<<" ";
	}

	return 0;
}