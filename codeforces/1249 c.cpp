#include<bits/stdc++.h>



#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define dbg(a) cout<<#a<<"= "<<a<<endl;

using namespace std;

typedef long long int ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll q;
    cin>>q;
    while(q--)
    {
        ll n;
        // cout<<n<<endl;
        cin>>n;

        vector<ll> v;

        while(n)
        {
            v.push_back(n%3);
            n=n/3;
        }
        v.push_back(0);

        // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        //     cout<<endl;

        ll x=v.size()-1;
        int f=0;

        for(int i=v.size()-2;i>=0;i--)
        {
            // if(f==1)
            // {
            //     v[i]=0;
            //     continue;
            // }
            if(v[i]==2)
            {
                f=1;
                break;
            }
            if(v[i]==0)
            {
                x=i;
            }
        }

        if(f==1)
        {
            // cout<<"y"<<endl;
            // dbg(x);
            for(int i=0;i<=x-1;i++) v[i]=0;
            v[x]=1;
        }

        ll ans =0;

        ll ml=1;

        for(int i=0;i<v.size();i++)
        {
            ans+=ml*v[i];
            // cout<<ans<<endl;
            ml=ml*3;
        }
        cout<<ans<<endl;
    }



	return 0;
}
