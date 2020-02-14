#include<bits/stdc++.h>

using namespace std;

struct PT
{
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p) const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (double c) const
    {
        return PT(x*c, y*c);
    }
    PT operator / (double c) const
    {
        return PT(x/c, y/c);
    }
};

double dot(PT p, PT q)
{
    return p.x*q.x+p.y*q.y;
}

double cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}


vector<pair<PT, int> > v;

bool helper(const PT &p)
{
    return cross(v[0].first, p)>0 || (cross(v[0].first, p)==0 && dot(v[0].first, p)>0);
}

int compareClockWise(pair<PT, int> a, pair<PT, int> b)
{
    return helper(a.first)==helper(b.first) && cross(a.first, b.first)>0 ||
        (helper(a.first)&& !helper(b.first));
}

int dpt[11000][5][3];

int dpf(int i, int st, int s)
{
    if(i>=v.size()) return 0;

    if(dpt[i][st][s]!=-1) return dpt[i][st][s];

    int p, q;
    p=q=INT_MAX;

    if(st==0)
    {
        if(v[i].second!=s)
        {
            p=1+dpf(i+1, st, s);
            q=dpf(i+1, st+1, s);
        }
        else
        {
            p=dpf(i+1, st, s);
        }
    }
    else if(st==1)
    {
        if(v[i].second==s)
        {
            p=1+dpf(i+1, st, s);
//            q=dpf(i+1, st+1);
        }
        else{
            p=dpf(i+1, st, s);
        }

    }
    else
    {
        if(v[i].second!=s)
        {
            p=1+dpf(i+1, st, s);
        }
        else
        {
            p=dpf(i+1, st, s);
        }
    }

    return dpt[i][st][s]=min(p, q);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;

        v.clear();
        memset(dpt, -1, sizeof dpt);

        for(int i=1;i<=n;i++)
        {
            int x, y;
            cin>>x>>y;
            PT p;
            p.x=x;
            p.y=y;
            v.push_back({p, 0});
        }


        for(int i=1;i<=m;i++)
        {
            int x, y;
            cin>>x>>y;
            PT p;
            p.x=x;
            p.y=y;
            v.push_back({p, 1});
        }

        sort(v.begin()+1, v.end(), compareClockWise);

//        for(int i=0;i<v.size();i++)
//        {
//            cout<<v[i].second<<endl;
////            cout<<v[i].first.x<<" "<<v[i].first.y<<endl;
//        }

        int p, q;
        p=q=INT_MAX;
        p=dpf(1, v[0].second, 0);
        for(int i=1;i<v.size();i++){
        if(v[i].second==1)
            q=i+dpf(i+1, 0, 1);
            break;
        }

        cout<<min(p, q)<<endl;
    }

    return 0;
}

