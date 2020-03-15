#include<bits/stdc++.h>


#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define dbg(a) cout<<#a<<" = "<<a<<endl

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;

//
//struct st{
//    ll a, b, c, t;
//    operator < (st a)
//    {
//        return t<a.t;
//    }
//};

typedef pair<ll, pair< ll, pair< ll, ll > > > st;
typedef pair< ll, pair< ll, ll > > st1;

#define t first
#define a second.first
#define b second.second.first
#define c second.second.second

map<st1, int> mp;

st bfs(st rt)
{
    mp[rt.second]=1;
    priority_queue<st, vector<st> , greater<st> > pq;
    pq.push(rt);

    while(!((pq.top().b%pq.top().a)==0 and (pq.top().c%pq.top().b)==0))
    {
        st fc=pq.top();
        fc.t++;
//        dbg(fc.t);
        pq.pop();
        if(fc.a>1)
        {
            fc.a--;
            if(mp[fc.second]==0) pq.push(fc), mp[fc.second]=1;
            fc.a++;
        }
        if(fc.a<fc.b)
        {
            fc.a++;
            if(mp[fc.second]==0) pq.push(fc), mp[fc.second]=1;
            fc.a--;
        }

        if(fc.b>1 and fc.b>fc.a)
        {
            fc.b--;
            if(mp[fc.second]==0) pq.push(fc), mp[fc.second]=1;
            fc.b++;
        }
        if(fc.b<fc.c)
        {
            fc.b++;
            if(mp[fc.second]==0) pq.push(fc), mp[fc.second]=1;
            fc.b--;
        }

        if(fc.c>1 and fc.c>fc.b)
        {
            fc.c--;
            if(mp[fc.second]==0) pq.push(fc), mp[fc.second]=1;
            fc.c++;
        }
        if(fc.c<10000)
        {
             fc.c++;
            if(mp[fc.second]==0) pq.push(fc), mp[fc.second]=1;
            fc.c--;
        }


    }

    return pq.top();
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int a1, b1, c1;
        cin>>a1>>b1>>c1;
        mp.clear();
        st f;
        f.t=0;
        f.a=a1;
        f.b=b1;
        f.c=c1;

        f=bfs(f);
        cout<<f.t<<endl;
        cout<<f.a<<" "<<f.b<<" "<<f.c<<endl;

    }

	return 0;
}



