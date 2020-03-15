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
        ll a, b;
        cin>>a>>b;
        if(a==b)
        {
            cout<<0<<endl;
        }
        else if(a<b)
        {
            if((b-a)%2==1)
                cout<<1<<endl;
            else cout<<2<<endl;
        }
        else
        {
            if((a-b)%2==1)
            {
                cout<<2<<endl;
            }
            else cout<<1<<endl;
        }
    }

	return 0;
}

