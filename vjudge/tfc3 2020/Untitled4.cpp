#include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define dbg puts("It's Just Begining.Wait For The End!!!!!\n")
    #define CHECK(x) cout << (#x) << " is " << (x) <<"\n";
    #define endl printf("\n")
    typedef pair<ll,ll> pii;
    #define pb push_back
    #define ms(a,b) memset(a, b, sizeof(a))
    #define in(x) scanf("%lld",&x)
    #define out(x) printf("%lld",x)
    #define X first
    #define Y second
    #define dou(x) cout<<fixed<<setprecision(6)<<x
ll par[26];
ll find_par(ll first,ll i)
{
    if(par[i]==i||par[i]==first)return i;
     return par[i]=find_par(first,par[i]);
}
int main()
{

    ll test;
    in(test);
    while(test--)
    {
    ll i,j,k,l,query;
    string s;
    cin>>s;
    in(query);
    for(i=0;i<25;i++)par[i]=i;
    char c,d;
    for(i=0;i<query;i++)
    {
        cin>>c>>d;
        par[(ll)(d-'A')]=(ll)(c-'A');
    }
    for(i=0;i<26;i++)
    {
        find_par(i,i);
        cout<<i<<" "<<par[i];endl;
    }
    for(i=0;i<s.size();i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            char ch=par[s[i]-'A']+'A';
            s[i]=ch;
        }
    }
    cout<<s;endl;
    }
    return 0;
}
