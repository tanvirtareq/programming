#include<bits/stdc++.h>

#define pp pair< int , pair<string , string > >

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int e;
        cin>>e;
        map<string, vector<pair<string, int > > > mp;
        set<string > st;

        string rt;

        for(int j=1; j<=e; j++)
        {
            string x, y;

            int a;
            cin>>x>>y>>a;
            if(j==1)
            {
                rt=x;

            }
            st.insert(x);
            st.insert(y);
            mp[x].push_back(make_pair(y, a));
            mp[y].push_back(make_pair(x, a));

        }

        priority_queue<pp, vector<pp>, greater<pp> > q;

        map<string, int> vis;

        vis[rt]=1;
        int n=st.size()-1;
        int tk=0;
        int ans=0;
        for(int j=0; j<mp[rt].size(); j++)
        {
            pair<string, int> pr;
            pr=mp[rt][j];
            if(vis[pr.first]==0)
            {
                q.push(make_pair(pr.second, make_pair(rt, pr.first)));

            }

        }
        int flag=0;

        while(tk<n)
        {
            if(q.empty())
            {
                flag=1;
                break;
            }

            pair<int, pair<string,string> > pr;
            pr=q.top();
            q.pop();
            rt=pr.second.first;
            string xrt=pr.second.second;
            if(vis[xrt]==0 && vis[rt]==1)
            {
                swap(rt, xrt);
            }
            else if(vis[xrt]==1 && vis[rt]==1)
                continue;

            vis[rt]=1;

            tk++;
            ans+=pr.first;

            for(int j=0; j<mp[rt].size(); j++)
            {
                pair<string, int> pr;
                pr=mp[rt][j];
                if(vis[pr.first]==0)
                {
                    q.push(make_pair(pr.second, make_pair(rt, pr.first)));

                }

            }

        }

        cout<<"Case "<<i<<": ";

        if(flag==0)
        {
            cout<<ans<<endl;

        }
        else cout<<"Impossible"<<endl;

    }

    return 0;
}
