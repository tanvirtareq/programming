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

 pt ar[50100];

ll dist(int i, int j)
{
    return (ar[i].x-ar[j].x)*(ar[i].x-ar[j].x)+(ar[i].y-ar[j].y)*(ar[i].y-ar[j].y)+(ar[i].z-ar[j].z)*(ar[i].z-ar[j].z);
}

int vis[50100];

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


int chk(int i,int j,int k)
{
    if(min(ar[i].x, ar[j].x)<=ar[k].x && ar[k].x<=max(ar[i].x, ar[j].x)
     && min(ar[i].y, ar[j].y)<=ar[k].y && ar[k].y<=max(ar[i].y, ar[j].y)
     && min(ar[i].z, ar[j].z)<=ar[k].z && ar[k].z<=max(ar[i].z, ar[j].z)) return 1;

        else return 0;
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

    // sort(ar+1, ar+n+1, cmp);

    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;

        // ll d=10e17;
        int id=i+1;

        while(vis[id]) id++;

        for(int j=i+2;j<=n;j++)
        {
            if(j==id || vis[j]) continue;

            if(chk(i, id, j))
            {
                id=j;
            }

        }

        cout<<ar[i].ind<<" "<<ar[id].ind<<endl;
        vis[i]=1;
        vis[id]=1;
    }

	return 0;
}
