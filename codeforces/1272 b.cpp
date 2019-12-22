#include<bits/stdc++.h>

#define ll long long
#define lu long long unsigned
#define ii pair<int, int>
#define vi vector<int>


using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll q;
    cin>>q;
    while(q--)
    {
        int u, l, r, d;
        u=l=r=d=0;
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='L') l++;
            if(s[i]=='U') u++;
            if(s[i]=='D') d++;
            if(s[i]=='R') r++;
        }

        u=d=min(u, d);
        l=r=min(l, r);
        if(u>0 and l>0)
        {
            cout<<2*(u+l)<<endl;
            for(int i=0;i<l;i++) cout<<"L";
            for(int i=0;i<u;i++) cout<<"U";
            for(int i=0;i<l;i++) cout<<"R";
            for(int i=0;i<u;i++) cout<<"D";
        }
        else if(u<=0 and l>0)
        {
            cout<<2<<endl;
            cout<<"LR";
        }
        else if(u>0 and l<=0)
        {
            cout<<2<<endl;
            cout<<"UD";
        }
        else cout<<0<<endl;
        cout<<endl;
    }

    return 0;
}


