#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll m, s;
    cin>>m>>s;
    string x;
    for(int i=1;i<=m;i++)
    {
        ll fc=min(9LL, s);
        s-=fc;
        x.push_back(fc+'0');
    }
    string y;
    int fk=0;
    if(x[m-1]=='0') y.push_back(1+'0'), fk=1;
    else y.push_back(x[m-1]);

    for(int i=m-2;i>=0;i--)
    {
        if(x[i]=='0') y.push_back('0');
        else
        {
            if(fk==1)
            {
                y.push_back(x[i]-1);
                fk=0;
            }
            else y.push_back(x[i]);
        }
    }

    if((s!=0 or fk==1 or x[0]=='0' or y[0]=='0') and m!=1) cout<<"-1 -1"<<endl;
    else if(m==1) cout<<x<<" "<<x<<endl;
    else cout<<y<<" "<<x<<endl;

    return 0;
}
