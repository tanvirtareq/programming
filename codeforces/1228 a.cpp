#include<bits/stdc++.h>

#define dbg(a) cout<<#a<<" "<<a<<endl
#define pb push_back
#define mk make_pair

using namespace std;

typedef long long ll;
typedef long long unsigned lu;

int vis[100010];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string a, b, c;

	cin>>a>>b;

	c.push_back(a[0]);
	vis[a[0]-'0']=1;

	int br=0;



	for(int i=1;i<a.size();i++)
	{
		for(int j=0;j<=9;j++)
		{
			if(br==0 and vis[j]==0 and (a[i]-'0')<=j)
			{
			
					vis[j]=1;
					c.push_back(j+'0');

					if((a[i]-'0')<j) br=1;

					break;

			}
			else if(br==1 and vis[j]==0)
			{
				vis[j]=1;
				c.push_back(j+'0');
				break;
			}
		}
	}

	if(a.size()<=c.size() and a<=c and c.size()<=b.size() and c<=b) cout<<c<<endl;

	else cout<<-1<<endl;

	return 0;


	return 0;
}