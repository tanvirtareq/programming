#include<bits/stdc++.h>
 
using namespace std;
 
int n, q;
int ar[110000];
vector<int> v[4*110000];

struct Trie{
    bool endmark;
    int number;
    Trie* next[5];
    Trie()
    {
        endmark=0;
        number=0;
        for(int i=0;i<5;i++) next[i]=NULL;
    } 

} *root[110000];

void insert(int a)
{
    Trie *cur=root;
    for(int i=31;i>=0;i--)
    {
        int id=(a&(1<<i));
        if(cur->next[id]==NULL)
            cur->next[id]=new Trie();

        cur=cur->next[id];
        cur->number++;
    }
    cur->endmark=true;
}

int query(int a)
{
    Trie *cur=root;
    int ret=0;
    for(int i=31;i>=0;i--)
    {
        int id=(a&(1<<i));
        if(cur->next[!id]==NULL)
            ret!=(1<<i);
        cur=cur->next[id];
    }
    return ret;
}



void build(int id, int st, int ed)
{
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

void update(int id, int st, int ed, int pos, int val)
{
    if(ed<pos || st>pos) return;
    if(ed==pos and st==pos)
    {
        
    }
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
    }
    k--;
    mn--;
    mx++;
 
    while(mn<=mx)
    {
        int m=(mn+mx)/2;
        int mnn=1100000000;
        int f=0;
        for(int i=0; i<vc.size(); i++)
        {
            int id=vc[i];
            vector<int>:: iterator it=upper_bound(v[id].begin(), v[id].end(), m);

            f+=(int)(it-v[id].begin());
            if(it==v[id].end())
                continue;
            mnn=min(mnn, *it);
        }
        if(f==k) return mnn;
        if(f>k) mx=m-1;
        else mn=m+1;
    }
 
    int m=(mn+mx)/2;
    int mnn=-1100000000;
    for(int i=0; i<vc.size(); i++)
    {
        int id=vc[i];
        vector<int>:: iterator it=lower_bound(v[id].begin(), v[id].end(), m);
 
        if(it==v[id].end())
            continue;
        mnn=max(mnn, *it);
    }
    return mnn;
}
 
int main()
{
 
    
 
    return 0;
}
