#include<bits/stdc++.h>
#define sz 100000
#define dfn v[x.second][i].first

using namespace std;

typedef long long int li;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int>, greater<int> > mnpqi;


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {

        int n;
        cin>>n;

        int gw[n+10];

        for(int i=1; i<=n; i++)
        {
            cin>>gw[i];
        }

        cout<<(int)sqrt(abs(gw[1]-gw[n]))<<endl;

    }



    return 0;
}


