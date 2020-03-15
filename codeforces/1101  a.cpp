#include<bits/stdc++.h>
#define pii pair<llu, llu>
#define inf ULLONG_MAX
//typedef pair<int, int> pii;
typedef long long unsigned llu;
typedef long long int lld;
using namespace std;


int main()
{

    int q;
    cin>>q;
    while(q--)
    {
        int l, r, d;
        cin>>l>>r>>d;

        if(l>d)
        {
            cout<<d<<endl;
        }
        else
        {
            int x=(r/d+1)*d;
//            cout<<ceil((float)r/2)
            cout<<x<<endl;
//            break;
        }

    }
    return 0;
}
