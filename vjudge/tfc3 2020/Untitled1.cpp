#include<bits/stdc++.h>


#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define dbg(a) cput<<#a<<" = "<<a<<endl

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int fc=0;
    while(t--)
    {
        string s;
        cin>>s;
        int p;
        cin>>p;
        vector<pair<char, char> > v;
        vector<int> adj[100];
//        for(int i=0;i<=26;i++) adj[i].push_back();

        for(int i=1;i<=p;i++)
        {
            char c1, c2;
            cin>>c1>>c2;
            v.push_back({c1, c2});
        }

        for(int i=v.size()-1;i>=0;i--)
        {
            int a=v[i].first-'A';
            int b=v[i].second-'A';
            if(adj[a].size()==0) adj[b].push_back(a);
            else
            adj[b].push_back(adj[a][adj[a].size()-1]);
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]<'A' || s[i]>'Z') continue;
            int a=s[i]-'A';
            int b;
            if(adj[a].size()==0) b=a;
            else
            b=adj[a][adj[a].size()-1];
            s[i]=(char)(b+'A');
        }
//        if(fc==1) cout<<endl;
        cout<<s<<endl;
        fc=1;
    }

	return 0;
}

/**
1
AABBCCY
5
B A
C B
D Y
D A
D B

*/

