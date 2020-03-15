
#include<bits/stdc++.h>


#define sci(a) scanf("%d", &a)
#define v(a) vector<a>
#define p(a, b) pair<a, b>

using namespace std;

typedef long long int li;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;

li  a, b ,ct;
bool vis[10001000];

int rec(int st,int m)
{
//    if(st==t) return tk;
//cout<<"as"<<st<<endl;

    if(st<0 or st>m) return INT_MAX;

    if(vis[st]==1) return INT_MAX;
    vis[st]=1;
    ct++;

    int p=rec(st+a, m);
    int q=rec(st-b, m);

    return min(p, q);

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    li n,m;

    cin>>n>>m;

    li ec=0, ek=0, oc=0, ok=0;

    while(n--)
    {
        li x;
        cin>>x;
        if(x%2==1) oc++;
        else ec++;
    }

     while(m--)
    {
        li x;
        cin>>x;
        if(x%2==1) ok++;
        else ek++;
    }

    cout<<min(ec, ok)+min(ek, oc)<<endl;

	return 0;
}



