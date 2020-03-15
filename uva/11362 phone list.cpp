#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

struct  node
{
	char val='*';
	int child[10]={0};
	bool ending=false;
};

int st=0;


bool insert_trie(string x,node trie[])
{
	int cur=0;
	for(int i=0;i<x.size();i++)
	{
		if(trie[cur].ending) return false;
		if(trie[cur].child[x[i]-'0']==0)
		{
			trie[cur].child[x[i]-'0']=++st;
			cur=st;
		}
		else
		{
			cur=trie[cur].child[x[i]-'0'];
		}
	}

	for(int i=0;i<10;i++)
	{
		if(trie[cur].child[i]!=0) return false;
	}

	trie[cur].ending=true;

	return true;

}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t, n;
//	cout<<t<<endl;
	cin>>t;
	while(t--)
	{
		node trie[100000];
		st=0;
		bool flag=true;
		cin>>n;
		cin.ignore();
		while(n--)
		{
			int par=-1;
			string x;
			cin>>x;
			if(flag==true)
			flag=insert_trie(x, trie);

		}

		if(flag) cout<<"YES"<<endl;

		else cout<<"NO"<<endl;

	}


	return 0;
}
