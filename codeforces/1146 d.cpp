
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

    li m;
    cin>>m>>a>>b;

    li g=__gcd(a, b);

    li lcm=(a/g)*b;

//    cout<<rec(a, 7)<<endl;

    int ans=0;

//    if(m<=lcm) lcm=m;

  li f1, f2;

    for(int i=0;i<=m;i++)
    {
        memset(vis, 0, sizeof vis);

        vis[0]=1;
        ct=0;

//        cout<<i<<endl;

        if(i<a) ct=1;

        else if(i>=a and a<=b and i<=2*b) ct=2;

        else if(i>=a and a>b and i<=2*b) ct=3;

        else {

            f1=i/g;
            break;
        }

//        ct++;

//
//        int x=rec(0+a, i);
        cout<<i<<" "<<ct<<endl;
        ans+=ct;

//        cout<<ans<<" "<<i<<" "<<ct<<endl;

    }

//    cout<<ans<<endl;

    f2=m/g+1;

//    cout<<f1<<" "<<f2<<endl;

    ans=ans+(f2*(f2+1)/2-f1*(f1+1)/2)*g;



    cout<<ans<<endl;

	return 0;
}


