#include<bits/stdc++.h>
#define ll long long
#define lu long long unsigned
#define dbg(a) cout<<#a<<"= "<<a<<endl

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int q;
	cin>>q;
	while(q--)
	{
		int r, c, k;
		cin>>r>>c>>k;
		char ch, ar[200][200];
		char f='$';
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
			{
				char c;
				cin>>c;
				ar[i][j]=c;
				if(c=='R' and k>0)
				{
					if(k>52) ar[i][j]='0'+(k-53);
					else if(k>26) ar[i][j]='a'+(k-27);
					else if(k>0) ar[i][j]='A'+(k-1);
					k--;
					if(f=='$') f=ar[i][j]; 
				}
			}
		int i=1, j=1;
		int fl=0;
		for(;i<=r;i++){
			for(;j<=c;j++){
				if(ar[i][j]==f) { fl=1; break;}
				ar[i][j]=f;
			}
			if(fl) break;
		}
		// dbg(i);
		// dbg(j);

		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				if(ar[i][j]=='.' or ar[i][j]=='R')
				{
					if(j>1) ar[i][j]=ar[i][j-1];
					else if(i>1) ar[i][j]=ar[i-1][j];
					// dbg(i);
					// dbg(j);
					// dbg(ar[i][j]);
				}
			}
			// dbg(i);
		}
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++) cout<<ar[i][j];
			cout<<endl;
		}
	}
	
	return 0;
}