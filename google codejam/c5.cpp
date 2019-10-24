#include<bits/stdc++.h>


using namespace std;

typedef long long unsigned li;

pair<li, li> Find(li x)
{
    for(li i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            return make_pair(i, x/i);
        }
    }

    return make_pair(0, 0);

}

int main()
{
    li n, t, l;

    cin>>t;

    for(li i=1;i<=t;i++)
    {
        cin>>n>>l;

        li br[l+10];
        vector<li> v;

        v.clear();

        bool vis[n+10];

        memset(vis, 0, sizeof vis);
        memset(br, 0, sizeof br);

        for(li j=1;j<=l;j++)
        {
            pair<li, li> p;

            cin>>br[j];
            p=Find(br[j]);

            if(p.first==0) return -123;

            if(vis[p.first]==0){
            v.push_back(p.first);
            vis[p.first]=1;
            }

            if(vis[p.second]==0){
            v.push_back(p.second);
            vis[p.second]=1;
            }

        }

        sort(v.begin(), v.end());

//        cout<<v[v.size()-1]<<endl;

        map<li, li> mp;

        for(li j=0;j<v.size();j++)
        {
            mp[v[j]]=j;
        }

        li x=br[1], a,b;

        for(li j=0;j<v.size();j++)
        {
            if(x%v[j]==0)
            {
                a=v[j];
                b=x/v[j];
                break;
            }
        }

        li f=1;

        while(f<l and br[f]==x)
        {
//            cout<<f<<endl;
            f++;

        }

//        cout<<f<<endl;

//        if(n)

        if(f%2==1)
        {
            if(br[f]%b==0)
            {
                swap(a, b);
            }

        }

        else if(f%2==0)
        {
            if(br[f]%b==1)
            {
                swap(a,b);
            }
        }

        vector<li> str;

//        if(a!=0)
        str.push_back(a);

//        else str.push_back(2);

        for(li j=1;j<=l;j++)
        {
            if(str[str.size()-1]<=br[j])
            str.push_back(br[j]/str[str.size()-1]);

//            else
//                str.push_back(1);
        }

        cout<<"Case #"<<i<<": ";
        for(int j=0;j<str.size();j++)
        {
            cout<<(char)('A'+mp[str[j]]);
        }
        cout<<endl;

    }


    return 0;
}

/**


2
103 31
217 1891 4819 2291 2987 3811 1739 2491 4717 445 65 1079 8383 5353 901 187 649 1003 697 3239 7663 291 123 779 1007 3551 1943 2117 1679 989 3053
10000 25
3292937 175597 18779 50429 375469 1651121 2102 3722 2376497 611683 489059 2328901 3150061 829981 421301 76409 38477 291931 730241 959821 1664197 3057407 4267589 4729181 5335543



2
103 35
217 217 217 217 1891 4819 2291 2987 2987 3811 1739 2491 4717 445 65 1079 8383 5353 901 187 649 1003 697 3239 7663 291 123 779 1007 3551 1943 2117 1679 989 3053


6 10 35 77 143 221 323 437 667 899 1147 1517 1763 2021 2491 3127 3599 4087 4757 5183 5767 6557 7387 8633 9797

*/
