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

 pt ar[2100];

ll dist(int i, int j)
{
    return (ar[i].x-ar[j].x)*(ar[i].x-ar[j].x)+(ar[i].y-ar[j].y)*(ar[i].y-ar[j].y)+(ar[i].z-ar[j].z)*(ar[i].z-ar[j].z);
}

int vis[2100];

int cmp(pt a, pt b)
{
    if(a.x==b.x)
    {
        if(a.y==b.y)
        {
            return a.z>b.z;
        }
        return a.y>b.y;
    }
    return a.x>b.x;
}


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


   

    for(int i=1;i<=n;i++)
    {

        cin>>ar[i].x>>ar[i].y>>ar[i].z;
        ar[i].ind=i;
    }

    sort(ar+1, ar+n+1, cmp);

    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;

        ll d=10e17;
        int id;

        for(int j=i+1;j<=n;j++)
        {
            if(vis[j]) continue;
            double fd=dist(i, j);
            if(fd<d)
            {
                d=fd;
                id=j;
            }

        }

        cout<<ar[i].ind<<" "<<ar[id].ind<<endl;
        vis[i]=1;
        vis[id]=1;
    }

	return 0;
}
