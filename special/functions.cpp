#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
typedef long long int lld;
typedef unsigned long long ull;

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

	for(int i=0;i<l/2;i++)
	{
		if(st[i]!=st[l-i-1])
			return 0;
	}

	return 1;
}

struct  propnode
{
	lld sum;
	lld prop;
	propnode()
	{
		prop=0;
		sum=0;
	}
};

void build(lld ar[], lld node, lld low, lld high, propnode tree[])
{
	if(low==high)
	{
		tree[node].sum=ar[low];

		//cout<<"node arpos val"<<endl;
		//cout<<node<<" "<<low<<" "<<ar[low]<<endl;
		return;
	}

	lld left=2*node;
	lld right=left+1;
	lld mid=(low+high)/2;

	//cout<<"node left right low high"<<endl;
	//cout<<node<<" "<<left<<" "<<right<<" "<<low<<" "<<high<<endl;

	build(ar, left, low, mid, tree);
	build(ar, right, mid+1, high, tree);

	tree[node].sum=tree[left].sum+tree[right].sum;

	return;

}

void update(lld ar[], lld node, lld low, lld high, lld ul, lld uh, lld val,  propnode tree[])
{
	if(ul<=low and uh>=high)
	{
	   //cout<<"low  high  sum"<<endl;
		//cout<<low<<" "<<high<<" "<<tree[node].sum<<endl;
		tree[node].prop+=val;
		tree[node].sum+=(high-low+1)*val;

		//cout<<"low high node sum  propagation"<<endl;

		//cout<<low<<" "<<high<<" "<<node<<" "<<tree[node].sum<<" "<<tree[node].prop<<endl;

		//cout<<node<<"  "<<tree[node].sum<<endl;
		//cout<<low<<" "<<high<<" "<<tree[node].sum<<endl;
		return;
	}

	if(uh<low or ul>high)
	{
		return;
	}



	lld left=2*node;
	lld right=left+1;
	lld mid=(low+high)/2;

	update(ar, left, low, mid, ul, uh, val, tree);
	update(ar, right, mid+1, high, ul, uh,val, tree);

	tree[node].sum=tree[left].sum+tree[right].sum+(high-low+1)*tree[node].prop;

	//cout<<"node  sum"<<endl;
	//cout<<node<<" "<<tree[node].sum<<endl;

	return;

}

lld query(lld ar[], lld node, lld low, lld high, lld ul, lld uh, lld carry,  propnode tree[])
{

	//cout<<"node  carry"<<endl;
	//cout<<node<<" "<<carry<<endl;
	if(ul<=low and uh>=high)
	{
		//cout<<"node  pre sum aft sum"<<endl;
		lld x=tree[node].sum+(high-low+1)*(carry);
		//cout<<node<<" "<<tree[node].sum<<" "<<x<<endl;

		return x;
	}

	if(uh<low or ul>high)
	{
		return 0;
	}



	lld left=2*node;
	lld right=left+1;
	lld mid=(low+high)/2;

	lld x=query(ar, left, low, mid, ul, uh, carry+tree[node].prop, tree);
	lld y=query(ar, right, mid+1, high, ul, uh,carry+tree[node].prop, tree);

	//cout<<x+y<<endl;

	return x+y;
}

inline power(lld b, lld p)
{
    if(p==0) return 1;
    else if(p==1) return b;
    lld x;

    x=power(b, p/2);
    if(p&1)
    {

        return x*x*b;
    }

    else
        return x*x;

}



int main()
{
//		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);

//		int_64 a;

        cout<<power(2, 2)<<endl;

		cout<<ispallindrome("avsa")<<endl;

	return 0;
}
