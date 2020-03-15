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


int n, e;
int clr[1100];
int clr1, clr0;

int dfs(int rt, int c, vector<int> v[1100])
{
    if(clr[rt]!=-1) return 0;

    clr[rt]=c;
    if(c==1) clr1++;
    else clr0++;

    for(int i=0;i<v[rt].size();i++)
    {
        int nw=v[rt][i];
        if(clr[nw]==-1)
        {
            dfs(nw, !c, v);
        }

    }
    return 0;

}



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {

        cin>>n>>e;
        vector<int> v[1100];


        memset(clr, -1, sizeof clr);

        clr0=0;
        clr1=0;

        while(e--)
        {
            int x, y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        int mx=0;

        for(int j=1;j<=n;j++)
        {
            clr0=0;
            clr1=0;

            dfs(j, 0, v);
            mx+=max(clr0, clr1);

        }
        cout<<"Case "<<i<<": "<<mx<<endl;

    }

	return 0;
}

/**
3

4 3
1 2
1 3
1 4

3 2
1 2
2 3

5 4
1 2
1 3
2 4
2 5

*/



