#include<bits/stdc++.h>



using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef priority_queue<ll> mxpqi;
typedef priority_queue<ll, vector<ll> , greater<ll> > mnpqi;



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int q;
    cin>>q;

    while(q--)
    {
        int x1=-100000;
        int x2=100000;
        int y1=-100000;
        int y2=100000;

        int n;

        cin>>n;

        while(n--)
        {
            int x, y, f1, f2, f3, f4;
            cin>>x>>y>>f1>>f2>>f3>>f4;
            (!f1)? x1=max(x1, x):x1=x1 ;
            (!f2)?  y2=min(y2, y):y2=y2 ;
            (!f3)? x2=min(x2, x):x2=x2 ;
            (!f4)? y1=max(y1, y):y1=y1 ;
        }

        if(x1<=x2 && y1<=y2)
        {

            cout<<1<<" "<<x1<<" "<<y1<<endl;
        }
        else cout<<0<<endl;


    }


	return 0;
}
