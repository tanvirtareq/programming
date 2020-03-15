#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<" = "<<x<<endl

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        string a, b, c;
        cin>>a>>b>>c;

        int f=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==c[i] || b[i]==c[i]) continue;
            f=1;
        }
        if(f)  cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

}

