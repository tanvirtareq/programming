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




int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<pair<int, string> > p;

    for(int i=0;i<n;i++)
    {
        int x;
        string str;
        cin>>str>>x;
        p.push_back(make_pair(x, str));

    }
    sort(p.begin(), p.end());

    int ans[n];

    for(int i=0;i<p.size();i++)
    {
        if(i<p[i].first)
        {
            cout<<-1<<endl;
            return 0;
        }

        int x=500+i;
        if(p[i].first!=0) x=ans[i-p[i].first-1];

        ans[i]=x;
    }

    for(int i=0;i<n;i++)
    {
        cout<<p[i].second<<" "<<ans[i]<<endl;
    }

	return 0;
}


