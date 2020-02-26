#include<bits/stdc++.h>


#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define dbg(a) cout<<#a<<" = "<<a<<endl

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        ll m, n;
        cin>>m>>n;
        string s;
        cin>>s;
        vector<ll> v;
        map<char, ll> mp;
        ll a[n+10];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            v.push_back(a[i]);
        }

//        int s=0;
//
//        for(int i=n;i>=1;i--)
//        {
//            s++;
//            v.push_back({i, s});
//        }


        sort(v.begin(), v.end());

        for(int i=0;i<m;i++)
        {
            auto it=lower_bound(v.begin(), v.end(), i+1);
            mp[s[i]]+=(v.size()-(ll)(it-v.begin()))+1;
//            dbg(s[i]);
//            dbg(mp[s[i]]);
        }

        for(char ch='a';ch<='z';ch++)
        {
            cout<<mp[ch]<<" ";
        }
        cout<<endl;
    }

	return 0;
}


