#include<bits/stdc++.h>

using namespace std;

int n, q;
int ar[110000];
vector<int> v[4*110000];

void build(int id, int st, int ed)
{

//    cout<<id<<" "<<st<<" "<<ed<<endl;

    if(st==ed)
    {
        v[id].push_back(ar[st]);
        return;
    }
    int m=(st+ed)/2;
    build(2*id, st, m);
    build(2*id+1, m+1, ed);
    v[id].resize(v[2*id].size()+v[2*id+1].size());
    merge(v[2*id].begin(), v[2*id].end(), v[2*id+1].begin(), v[2*id+1].end(), v[id].begin());
    return;
}

void query(int id, int st, int ed, int l, int r, vector<int> &vc)
{
    if(ed<l || st>r)
        return ;
    if(l<=st and ed<=r)
    {
        vc.push_back(id);
        return;
    }

    int m=(st+ed)/2;
    query(2*id, st, m, l, r, vc);
    query(2*id+1, m+1, ed, l, r, vc);
    return;
}

int res(int l, int r, int k)
{
    vector<int>vc;
    query(1, 1, n, l, r, vc);

    int mn=1100000000;
    int mx=-mn;

    for(int i=0; i<vc.size(); i++)
    {
        int id=vc[i];
        mn=min(mn, v[vc[i]][0]);
        mx=max(mx, v[id][v[id].size()-1]);

//        for(int j=0;j<v[id].size();j++) cout<<v[id][j]<<" ";
//        cout<<endl;
    }
    k--;
    mn--;
    mx++;

    while(mn<=mx)
    {
//        cout<<mn<<" "<<mx<<endl;
        int m=(mn+mx)/2;
//        cout<<m<<endl;

        int mnn=1100000000;
        int f=0;
        for(int i=0; i<vc.size(); i++)
        {
            int id=vc[i];
            vector<int>:: iterator it=upper_bound(v[id].begin(), v[id].end(), m);

//            cout<<*it<<endl;
            f+=(int)(it-v[id].begin());
            if(it==v[id].end())
                continue;
            mnn=min(mnn, *it);
//            cout<<mnn<<endl;
        }
        if(f==k) return mnn;
        if(f>k) mx=m-1;
        else mn=m+1;
    }
//    cout<<mn<<" "<<mx<<endl;

    int m=(mn+mx)/2;
//    cout<<m<<endl;
    int mnn=-1100000000;
    for(int i=0; i<vc.size(); i++)
    {
        int id=vc[i];
        vector<int>:: iterator it=lower_bound(v[id].begin(), v[id].end(), m);

//        cout<<*it<<endl;
        if(it==v[id].end())
            continue;
        mnn=max(mnn, *it);
    }
    return mnn;
}

int main()
{

    scanf("%d%d", &n, &q);

    for(int i=1; i<=n; i++)
    {
        scanf("%d", &ar[i]);
    }
    build(1, 1, n);
//    cout<<"yes"<<endl;
    while(q--)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", res(l, r, k));
    }

    return 0;
}

/**

7 3
1 5 2 6 3 7 4
2 5 3
4 4 1
1 7 3

7 3
1 5 2 6 3 7 4
2 5 3
4 4 1
1 7 1


7 3
1 5 2 6 3 7 4
2 5 3
4 4 1
1 7 7

7 3
1 5 2 6 3 7 4
1 7 7

7 100
1 2 3 4 5 6 7
1 3 1
1 1 1
1 2 1
1 2 2
1 3 1
1 3 2
1 3 3
1 4 1
1 4 2
1 4 3
1 4 4
1 5 1
1 5 2
1 5 3
1 5 4
1 5 5
1 6 1
1 6 2
1 6 3
1 6 4
1 6 5
1 6 6
1 7 1
1 7 2
1 7 3
1 7 4
1 7 5
1 7 6
1 7 7
2 2 1
2 3 1
2 3 2
2 4 1
2 4 2
2 4 3
2 5 1
2 5 2
2 5 3
2 5 4
2 6 1
2 6 2
2 6 3
2 6 4
2 6 5
2 7 1
2 7 2
2 7 3
2 7 4
2 7 5
2 7 6
3 3 1
3 4 1
3 4 2
3 5 1
3 5 2
3 5 3
3 6 1
3 6 2
3 6 3
3 6 4
3 7 1
3 7 2
3 7 3
3 7 4
3 7 5
4 4 1
4 5 1
4 5 2
4 6 1
4 6 2
4 6 3
4 7 1
4 7 2
4 7 3
4 7 4
5 5 1
5 6 1
5 6 2
5 7 1
5 7 2
5 7 3
6 6 1
6 7 1
6 7 2
7 7 1


7 100
10 20 30 40 50 60 70
1 3 1
1 1 1
1 2 1
1 2 2
1 3 1
1 3 2
1 3 3
1 4 1
1 4 2
1 4 3
1 4 4
1 5 1
1 5 2
1 5 3
1 5 4
1 5 5
1 6 1
1 6 2
1 6 3
1 6 4
1 6 5
1 6 6
1 7 1
1 7 2
1 7 3
1 7 4
1 7 5
1 7 6
1 7 7
2 2 1
2 3 1
2 3 2
2 4 1
2 4 2
2 4 3
2 5 1
2 5 2
2 5 3
2 5 4
2 6 1
2 6 2
2 6 3
2 6 4
2 6 5
2 7 1
2 7 2
2 7 3
2 7 4
2 7 5
2 7 6
3 3 1
3 4 1
3 4 2
3 5 1
3 5 2
3 5 3
3 6 1
3 6 2
3 6 3
3 6 4
3 7 1
3 7 2
3 7 3
3 7 4
3 7 5
4 4 1
4 5 1
4 5 2
4 6 1
4 6 2
4 6 3
4 7 1
4 7 2
4 7 3
4 7 4
5 5 1
5 6 1
5 6 2
5 7 1
5 7 2
5 7 3
6 6 1
6 7 1
6 7 2
7 7 1

*/
