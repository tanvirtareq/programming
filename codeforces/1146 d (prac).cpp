
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
//bool ct[10001000];

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

    li m;
    cin>>m>>a>>b;

    li g=__gcd(a, b);

    li lcm=(a/g)*b;

//    cout<<rec(a, 7)<<endl;

    int ans=0;

//    if(m<=lcm) lcm=m;

    for(int i=0;i<=lcm+10;i++)
    {
//        memset(vis, 0, sizeof vis);

        vis[0]=1;
        ct=0;
        ct++;

        int x=rec(0+a, i);
        cout<<i<<" "<<ct<<endl;
        ans+=ct;

    }

    if(lcm==m) cout<<ans<<endl;

    else
    {
        for(li i=lcm+1;i<=m;i++)
        {
            if(i%g==0)
            {
                ans+=i/g+1;
            }
        }
         cout<<ans<<endl;
    }



	return 0;
}

