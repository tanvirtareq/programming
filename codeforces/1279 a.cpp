#include<bits/stdc++.h>
#define ll long long
#define lu long long unsigned
#define ii pair<int, int>
#define dbg(a) cout<<#a<<"="<<a<<endl

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a, a+3);
        if(a[0]+a[1]>=a[2]-1)
        {
            cout<<"Yes"<<endl;

        }
        else cout<<"No"<<endl;

    }

}

