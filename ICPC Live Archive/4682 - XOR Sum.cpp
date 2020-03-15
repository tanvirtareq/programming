#include<bits/stdc++.h>

using namespace std;

int ar[110000];

struct Trie{
	bool endmark;
	Trie* next[5];
	Trie()
	{
		endmark=0;
		for(int i=0;i<5;i++) next[i]=NULL;
	} 

} *root;

void insert(int a)
{
	Trie *cur=root;
	for(int i=31;i>=0;i--)
	{
		int id=(a&(1<<i))!=0;
		if(cur->next[id]==NULL)
			cur->next[id]=new Trie();

		cur=cur->next[id];
	}
	cur->endmark=true;
}

int query(int a)
{
	Trie *cur=root;
	int ret=0;
	for(int i=31;i>=0;i--)
	{
		int id=(a&(1<<i))!=0;
		// cout<<id<<endl;
		// if(cur->next[id]==NULL)
		// {
		// 	cout<<"askldf"<<endl;
		// }
		// if(cur->next[!id]==NULL)
		// {
		// 	cout<<"fa"<<endl;
		// }
		if(cur->next[!id]!=NULL)
		{
			ret=ret|(1<<i), cur=cur->next[!id];
			// cout<<"alksdj"<<endl;
		}

		else 
		cur=cur->next[id];
	// cout<<ret<<endl;

	}
	// cout<<endl<<endl;
	return ret;
}



int main()
{
	int n;
	scanf("%d", &n);
	int x=0;
	for(int i=1;i<=n;i++)
	{
		int y;
		scanf("%d", &y);
		y^=x;
		ar[i]=y;
		x=y;
		cout<<ar[i]<<" ";
	}

	root=new Trie();
	insert(ar[1]);
	int mx=ar[1];
	for(int i=2;i<=n;i++)
	{
		mx=max(mx, query(ar[i]));
		cout<<mx<<endl;
		insert(ar[i]);
	}
	cout<<mx<<endl;

	return 0;
}