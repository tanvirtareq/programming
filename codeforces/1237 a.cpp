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

    ll n;
    cin>>n;

    ll ar[n+10], br[n+10];

    ll cr=0, crmn=0;

    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
        if(ar[i]%2==0) br[i]=ar[i]/2;

        else if(ar[i]>=0)
        {
            if(cr==1)
            {
                cr=0;
                br[i]=(ar[i]+1)/2;
            }
            else 
            {
                cr=1;
                br[i]=ar[i]/2;
            }
        }

        else 
        {
            if(crmn==0)
            {
                crmn=1;
                br[i]=ar[i]/2;

            }
            else 
            {
                crmn=0;
                br[i]=(ar[i]-1)/2;

            }
        }


    }

    for(int i=1;i<=n;i++) cout<<br[i]<<endl;


	return 0;
}
