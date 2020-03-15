#include<bits/stdc++.h>
#define ll long long

using namespace std;

int parent[110000];


void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}


int main()
{
	map<string, int> mp;
	int n, m;
	scanf("%d%d", &n, &m);
	int t=0;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		mp[s]=++t;
	}

	for(int i=1;i<=t;i++)
		make_set(i);

	while(m--){
		int ty;
		string a, b;
		cin>>ty>>a>>b;

		if(ty==1)
		{
			union_sets(mp[a], mp[b]);
		}
		else {
			if(find_set(mp[a])==find_set(mp[b]))
			{
				puts("yes");
			}
			else puts("no");
		}

	}
	
	return 0;
}