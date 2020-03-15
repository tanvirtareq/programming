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
typedef priority_queue<li> mxpqli;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;


int main()
{

    int n, m;

    map<int, int> mp;
    map<int, int>::iterator it;

    cin>>n>>m;

    while(n--)
    {
        int x;
        cin>>x;
        mp[x]++;
    }

    int ans=0;

    for(it=mp.begin();it!=mp.end();it++)
    {
        int x=it->first;
        while(mp[x]!=0 and mp[x+1]!=0 and mp[x+2]!=0)
        {
            ans++;
            mp[x]--;
            mp[x+1]--;
            mp[x+2]--;
        }

    }

    for(it=mp.begin();it!=mp.end();it++)
    {
        int x=it->first;

        ans+=mp[x]/3;


    }

    cout<<ans<<endl;

	return 0;
}
