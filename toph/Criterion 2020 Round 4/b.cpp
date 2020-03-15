#include<bits/stdc++.h>
#define ll long long

using namespace std;
#define pi  3.14159265358979323846
#define MX 100000010

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("unroll-loops")

int parent[MX], size[MX];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}


void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (a > b)
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

bool ase[MX];

int main()
{
	ll n, g;
	scanf("%lld%lld", &g, &n);

	int xr=0;
	ll gk=1;
	make_set(1);
	xr^=1;
	ase[1]=1;
	for(ll i=1;i<n;i++)
	{
		gk=(gk*g)%(n+1);
		// if(ase[gk]) continue;
		// ase[gk]=1;
		// make_set(gk);
		// if( gk<n and ase[gk+1]) union_sets(gk, gk+1);
		// if(gk>1 and ase[gk-1]) union_sets(gk-1, gk);
		cout<<gk<<endl;

		xr^=gk;

	}
	printf("%d\n", xr);

	return 0;
}