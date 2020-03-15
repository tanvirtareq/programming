#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define N 1100000
#define MX 300
using namespace std;

string x;

int bondodp[MX], lkuladp[MX], rkuladp[MX], kuladp[MX];

int chk(int i)
{
    if(i-2>=0 and x[i-2]=='X' and x[i-1]=='X') return 1;
    if(i-1>=0 and x[i-1]=='X' and i+1<x.size() and x[i+1]=='X') return 1;
    if(i+2<x.size() and x[i+1]=='X' and x[i+2]=='X') return 1;
    return 0;
}

int bipod(int i)
{
    if(i-2>=0 and x[i-2]=='X' and x[i-1]=='.') return 1;
    if(i-2>=0 and x[i-2]=='.' and x[i-1]=='X') return 1;
    if(i-1>=0 and x[i-1]=='X' and i+1<x.size() and x[i+1]=='.') return 1;
    if(i-1>=0 and x[i-1]=='.' and i+1<x.size() and x[i+1]=='X') return 1;
    if(i+2<x.size() and x[i+1]=='X' and x[i+2]=='.') return 1;
    if(i+2<x.size() and x[i+1]=='.' and x[i+2]=='X') return 1;
    return 0;
}

int bondo(int ct)
{
//    cout<<ct<<endl;
    if(ct<=2) return 0;

    if(bondodp[ct]!=-1) return bondodp[ct];

    map<int, int> mp;

    for(int i=2;i<ct;i++)
    {
        mp[bondo(i)^bondo(ct-i-1)]=1;
    }

    for(int i=0;;i++)
    {
        if(mp[i]==0) return bondodp[ct]=i;
    }

}

int lkula(int ct)
{
    if(ct<=0) return 0;
    if(ct<=2) return 0;

    if(lkuladp[ct]!=-1) return lkuladp[ct];

    map<int, int> mp;

    for(int i=2;i<ct;i++)
    {
        mp[lkula(i)^bondo(ct-i-1)]=1;
    }

    for(int i=0;;i++)
        if(mp[i]==0) return lkuladp[ct]=i;
}

int rkula(int ct)
{
//    cout<<"ct "<<ct<<endl;
    if(ct<=0) return 0;

    if(ct<=2) return rkuladp[ct]=0;

    if(rkuladp[ct]!=-1) return rkuladp[ct];
    map<int, int> mp;
    for(int i=2;i<ct;i++)
        mp[bondo(i)^rkula(ct-i-1)]=1;

    for(int i=0;i<ct;i++)
        if(mp[i]==0) return rkuladp[ct]=i;
}

int kula(int ct)
{
    if(ct<=0) return 0;

    if(ct<=2) return 0;

    if(kuladp[ct]!=-1) return kuladp[ct];

    map<int, int> mp;

    for(int i=2;i<ct;i++)
        mp[lkula(i)^rkula(ct-i-1)]=1;

    for(int i=0;;i++)
        if(mp[i]==0) return kuladp[ct]=i;
}

int solve()
{
    int xr=0;
    int kl=1;
    int ct=0;
    for(int i=0;i<x.size();i++)
    {
        if(x[i]=='X')
        {
            if(kl) xr^=lkula(ct);
            else xr^=bondo(ct);
            ct=0;
            kl=0;
        }
        else ct++;
    }
    if(kl==0) xr^=rkula(ct);
    else xr^=kula(ct);

//    cout<<endl<<endl;
//    cout<<ct<<" "<<rkuladp[ct]<<endl;
    return xr==0;
}

int buddi(int id)
{
//    if(id==3) cout<<bipod(id)<<endl;
    if(bipod(id)) return 0;

    x[id]='X';

    int p=solve();
    x[id]='.';
    return p;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(bondodp, -1, sizeof bondodp);
    memset(lkuladp, -1, sizeof lkuladp);
    memset(rkuladp, -1, sizeof rkuladp);

    int t;
    cin>>t;
    int in=0;
    while(t--)
    {
        in++;
        int f=0;

        cin>>x;
        cout<<"Case "<<in<<": ";
        for(int i=0;i<x.size();i++)
        {
            if(x[i]=='.')
            {
                if(chk(i)||buddi(i))
                {
                    cout<<i+1<<" ";
                    f=1;
                }
            }
        }
        if(f==0) cout<<0<<endl;
        else cout<<endl;

        cout<<lkuladp[3]<<" "<<rkuladp[14]<<endl;

        for(int i=1;i<=14;i++) cout<<rkuladp[i]<<endl;

    }

}

/**

X.....X..X.......X....X..X

..................
*/
