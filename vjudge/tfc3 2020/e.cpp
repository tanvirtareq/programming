#include<bits/stdc++.h>


#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define dbg(a) cput<<#a<<" = "<<a<<endl
#define MX  20000101

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;

ll sm[MX];

void sv()
{
    for(int i=1;i<=MX;i++)
    {
        for(int j=i;j<=MX;j+=i)
        {
            sm[j]+=i;
        }
    }

    for(int i=2;i<=MX;i++) sm[i]+=sm[i-1];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    sv();
    while(cin>>n)
    {
        if(n==0) break;
        cout<<sm[n]-sm[1]<<endl;

    }



	return 0;
}

/**


*/


