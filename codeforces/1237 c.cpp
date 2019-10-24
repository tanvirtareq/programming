#include<bits/stdc++.h>



#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define dbg(a) cout<<#a<<"= "<<a<<endl;

using namespace std;

typedef long long int ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;

struct pt{
    int x, y, z, ind;

};

int cmp(pt a, pt b)
{
    if(a.x==b.x)
    {
        if(a.y==b.y)
        {
            return a.z<b.z;
        }
        return a.y<b.y;
    }
    return a.x<b.x;
}

int vis[510000];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;


    pt ar[510000];

    for(int i=1;i<=n;i++)
    {

        cin>>ar[i].x>>ar[i].y>>ar[i].z;
        ar[i].ind=i;
    }

    sort(ar+1, ar+n+1, cmp);

    for(int i=1;i<n;i++)
    {
        // cout<<ar[i].x<<" "<<ar[i].y<<" "<<ar[i].z<<endl;
        if(vis[ar[i].ind]) continue;

        int j=i+1;
        while(vis[ar[j].ind] and j<=n) j++;

        if(j>n) break;

        if(ar[i].x==ar[j].x and ar[i].y==ar[j].y)
        {
            cout<<ar[i].ind<<" "<<ar[j].ind<<endl;
            vis[ar[i].ind]=1;
            vis[ar[j].ind]=1;
        }


    }

    for(int i=1;i<n;i++)
    {
        if(vis[ar[i].ind]) continue;

        int j=i+1;
        while(vis[ar[j].ind] and j<=n) j++;

        if(j>n) break;

        if(ar[i].x==ar[j].x)
        {
            cout<<ar[i].ind<<" "<<ar[j].ind<<endl;
            vis[ar[i].ind]=1;
            vis[ar[j].ind]=1;
        }
    }

    for(int i=1;i<n;i++)
    {
        if(vis[ar[i].ind]) continue;

        int j=i+1;
        while(vis[ar[j].ind] and j<=n) j++;

        if(j>n) break;

            cout<<ar[i].ind<<" "<<ar[j].ind<<endl;
            vis[ar[i].ind]=1;
            vis[ar[j].ind]=1;
        

    }


	return 0;
}
