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

        double d[n+10];

        for(int i=2;i<=n;i++)
        {
            d[i]=DBL_MAX;
        }

        d[1]=0;

        priority_queue<pair<double, int> > pq;

        pq.push(make_pair(-0, 1));

        while(!pq.empty())
        {
            pair<double, int> x;

            x=pq.top();
            pq.pop();

            if(x.second==n)
            {
                cout<<(int)(-x.first)<<endl;
                break;
            }

            for(int i=1;i<=n;i++)
            {
                if(i!=x.second)
                {
                    if(-x.first + sqrt(abs(gw[x.second]-gw[i])<d[i]))
                    {
                        d[i]=-x.first + sqrt(abs(gw[x.second]-gw[i]));
                        pq.push(make_pair(-d[i], i));

                    }

                }
            }


        }

    }



    return 0;
}

