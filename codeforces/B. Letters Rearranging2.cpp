#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

void dfs(vector<int> v[], int r, int vis[])
{
	for(int i=0;i<v[r].size();i++)
	{
		int x=v[r][i];
		if(vis[x]!=1)
		{
			vis[x]=1;
			dfs(v, x, vis);
		}
	}
	return;
}

void topsort(std::vector<int> v[], int indeg[], int n)
{

    queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(indeg[i]==0) q.push(i);
	}

	while(!q.empty())
	{
		int x=q.front();

		cout<<x<<" ";
		q.pop();

		for(int i=0;i<v[x].size();i++)
		{
			indeg[v[x][i]]--;
			if(indeg[v[x][i]]==0) q.push(v[x][i]);
		}
	}
	return;

}

bool ispallindrome(string st)
{
	int l=st.size();

	//printf("%c\n", st[0]);

	for(int i=0;i<l/2;i++)
	{
		//cout<<st[i]<<" "<<st[l-i-1]<<endl;
		if(st[i]!=st[l-i-1])
			return 0;
	}

	return 1;
}

int main()
{
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);

		//cout<<ispallindrome("aba")<<endl;

		int t;
		cin>>t;
		while(t--)
		{
			string st;
			cin>>st;

			string x=st;

			if(ispallindrome(st))
            {

                next_permutation(st.begin(), st.end());
            }
           // cout<<st<<endl;
            else
            {

                 cout<<st<<endl;
                 continue;
            }
			while(st!=x and ispallindrome(st))
			{
				//cout<<st<<endl;
				next_permutation(st.begin(), st.end());
				//cout<<st<<endl;
			}

			if(st==x) cout<<"-1"<<endl;

			else  cout<<st<<endl;
		}

	return 0;
}
