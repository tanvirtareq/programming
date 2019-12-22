#include<bits/stdc++.h>
#define ii pair<int, int>

using namespace std;

vector<pair<int, int> >p, v;

int cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second>p2.second;
}

int ispo(vector<ii> v, int id, int r)
{
    if(v.size()<=1) return 1;

    v.erase(v.begin()+id);
    for(int i=0;i<v.size();i++)
    {
        if(v[i].second<=r)
        {
            if(ispo(v, i, r-v[i].second)) return 1;
        }
    }
    return 0;

}

int main(){
    int n, r;
    cin>>n>>r;
    for(int i=1;i<=n;i++)
    {
        int a, b;
        cin>>a>>b;
        if(b>=0)
        {
            p.push_back({a, b});
        }
        else
        {
            v.push_back({a, -b});
        }
    }
    int f=0;
    sort(p.begin(), p.end());
    for(int i=0;i<p.size();i++)
    {
        if(p[i].first>r)
        {
            f=1;
            break;
        }
        r+=p[i].second;
    }
    sort(v.begin(), v.end(), cmp);

    if(f) return cout<<"NO"<<endl, 0;

    for(int i=0;i<v.size();i++)
    {
        if(ispo(v, i, r-v[i].second))
        {
            return cout<<"YES"<<endl, 0;
        }
    }

    cout<<"NO"<<endl;

    return 0;
}


