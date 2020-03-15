#include<bits/stdc++.h>

using namespace std;

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin>>a>>b;

    int d=0;
    int c=0;

    for(int i=0; i<b.size(); i++)
    {
        d+=b[i]-'0';
        c+=a[i]-'0';
    }

    int l=b.size();
    int ans=0;
    if((d+c)%2==0)
    {
        ans++;
    }
    for(int i=1; i+l<=a.size(); i++)
    {
        c=c-a[i-1]+a[i-1+l];
        if((d+c)%2==0)
        {
            ans++;
//            cout<<i<<endl;
        }
    }

    cout<<ans<<endl;




}

