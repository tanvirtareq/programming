#include<bits/stdc++.h>


#define watch(x) cout<<x<<endl;

using namespace std;

int t, n, s[1000], f[1000];

void show(vector<int> v)
{
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";

    cout<<endl;

    return;

}

bool cmpr(pair<int, pair<int, int> > p, pair<int, pair<int, int> >q)
{
    if(p.second.second<q.second.second) return true;

    return false;

}



int main()
{

    cin>>t;

    while(t--)
    {
        cin>>n;

        vector<pair<int, pair<int, int> > > v;

        for(int i=1;i<=n;i++)
            cin>>s[i];

        for(int i=1;i<=n;i++)
            cin>>f[i];

        for(int i=1;i<=n;i++)
        {
            v.push_back(make_pair(i, make_pair(s[i], f[i])));
        }

        sort(v.begin(), v.end(), cmpr);
        int f=0;

        for(int i=0;i<v.size();i++)
        {
            if(v[i].second.first>=f)
            {
//                watch(f);
                f=v[i].second.second;
                cout<<v[i].first<<" ";

            }

        }
        cout<<endl;

    }

    return 0;
}

/**

2
6
1 3 0 5 8 5
2 4 6 7 9 9
8
75250 50074 43659 8931 11273 27545 50879 77924
112960 114515 81825 93424 54316 35533 73383 160252

*/
