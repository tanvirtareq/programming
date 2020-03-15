#include<bits/stdc++.h>
#define mxx 100000000
#define ll long long
using namespace std;

void find_lps(vector<ll> &pattern, ll lps[])
{
    ll i=1, j=0;
    lps[0]=0;
    while(i<pattern.size())
    {
        if(pattern[i]==pattern[j])
        {
            j++;
            lps[i]=j;
            i++;
        }
        else if(j!=0) j=lps[j-1];
        else
        {
            lps[i]=0;
            i++;
        }
    }
    return ;
}

ll kmpSearch(vector<ll>  &text, vector<ll>  &pattern, ll lps[])
{
    ll i=0, j=0, numberOfOccurance=0;
    while(i<text.size())
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
            if(j>=pattern.size())
            {
                numberOfOccurance++;
                j=lps[j-1];
            }
        }
        else if(j!=0) j=lps[j-1];
        else i++;
    }
    return numberOfOccurance;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, w;
    cin>>n>>w;

    if(n==1 || w==1 )
    {
        cout<<n*w<<endl;
        return 0;
    }

    vector<ll> t;
    ll prv;
    cin>>prv;
    for(ll i=1;i<n;i++)
    {
        ll x;
        cin>>x;
        ll y=x-prv;
        prv=x;
        t.push_back(y);

    }

    vector<ll> pt;
    cin>>prv;
    for(ll i=1;i<w;i++)
    {
        ll x;
        cin>>x;
        ll y=x-prv;
        prv=x;
        pt.push_back(y);
    }

    ll lps[220000];
    find_lps(pt, lps);


    ll numberOfOccurance=kmpSearch(t, pt, lps);
    cout<<numberOfOccurance<<endl;



    return 0;
}



