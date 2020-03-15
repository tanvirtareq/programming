#include<bits/stdc++.h>
#define ll long long
#define md 1000000007
#define nl '\n'
#define MX 201000
using namespace std;
bool ase[201000];

int trr[4*MX], td[4*MX];

void rinsert(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        trr[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            rinsert(v*2, tl, tm, pos, new_val);
        else
            rinsert(v*2+1, tm+1, tr, pos, new_val);
        trr[v] = min(trr[v*2], trr[v*2+1]);
    }
}


void rdlt(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        trr[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            rdlt(v*2, tl, tm, pos, new_val);
        else
            rdlt(v*2+1, tm+1, tr, pos, new_val);
        trr[v] = min(trr[v*2], trr[v*2+1]);
    }
}

int rmin(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return MX;
    if (l == tl && r == tr) {
        return trr[v];
    }
    int tm = (tl + tr) / 2;
    return min(rmin(v*2, tl, tm, l, min(r, tm)), rmin(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void dinsert(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        td[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            dinsert(v*2, tl, tm, pos, new_val);
        else
            dinsert(v*2+1, tm+1, tr, pos, new_val);
        td[v] = min(td[v*2], td[v*2+1]);
    }
}


void ddlt(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        td[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            ddlt(v*2, tl, tm, pos, new_val);
        else
            ddlt(v*2+1, tm+1, tr, pos, new_val);
        td[v] = min(td[v*2], td[v*2+1]);
    }
}

int dmin(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return MX;
    if (l == tl && r == tr) {
        return td[v];
    }
    int tm = (tl + tr) / 2;
    return min(dmin(v*2, tl, tm, l, min(r, tm)), dmin(v*2+1, tm+1, tr, max(l, tm+1), r));
}





int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  

    for(int i=0;i<4*MX;i++)
    {
    	trr[i]=MX;
    	td[i]=MX;
    }

	int n;
	string s;
	cin>>n;
	cin>>s;
	set<int> r, d;

	for(int i=0;i<n;i++)
	{
		if(s[i]=='R') rinsert(1, 0, MX, i, i);
		else dinsert(1, 0, MX, i, i);
	}

	int i=0;

	while(td[1]<MX and trr[1]<MX)
	{
		if(ase[i]==1)
		{
			i=(i+1)%n;
			continue;
		}
		if(s[i]=='R')
		{
			int x=dmin(1, 0, MX, i, MX);
			if(x==MX) x=td[1];
			// cout<<x<<"aj"<<endl;

			ase[x]=1;
			ddlt(1, 0, MX, x , MX);
		}
		else
		{
			int x=rmin(1, 0, MX, i, MX);
			if(x==MX) x=trr[1];
			// cout<<x<<endl;

			ase[x]=1;
			rdlt(1, 0, MX, x , MX);
		}
		i=(i+1)%n;
	}

	if(td[1]==MX) cout<<"R"<<nl;
	else cout<<"D"<<nl;

	return 0;
}