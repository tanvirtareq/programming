#include<bits/stdc++.h>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int a;

	cin>>a;
	while(a--)
	{

		string x;
		cin>>x;
		int f=0;

		if(x[0]=='?' and x[1]=='a') x[0]='b';
		else if(x[0]=='?') x[0]='a';

		for(int i=1;i<x.size();i++)
		{
			if(x[i]=='?')
			{
				if(x[i-1]=='a' and x[i+1]=='b') x[i]='c';
				else if(x[i-1]=='b' and x[i+1]=='a') x[i]='c';
				else if(x[i-1]=='a' and x[i+1]=='c') x[i]='b';
				else if(x[i-1]=='c' and x[i+1]=='a') x[i]='b';
				else if(x[i-1]=='c' and x[i+1]=='b') x[i]='a';
				else if(x[i-1]=='b' and x[i+1]=='c') x[i]='a';
				
				else if(x[i-1]=='b') x[i]='a';

				else if(x[i-1]=='c') x[i]='a';

				else if(x[i-1]=='a') x[i]='b';

				else if(x[i+1]=='b') x[i]='a';

				else if(x[i+1]=='c') x[i]='a';

				else if(x[i+1]=='a') x[i]='b';
									
			}
			else 
			{
				if(x[i-1]==x[i] or x[i+1]==x[i]) 
				{
					cout<<-1<<endl;
					f=1;
					break;
				}
			}
		}

		if(!f) cout<<x<<endl;
	}

	return 0;
}