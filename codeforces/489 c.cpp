#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll m, s;
    cin>>m>>s;
    int s1=s;
    string x;
    int fl=0;
    for(int i=1;i<=m;i++)
    {
        ll fc=min(9LL, s);
        if(fc) fl=1;
        s-=fc;
        x.push_back(fc+'0');
    }
    if(s>0 or (fl==0 and m>1))
    {
        cout<<"-1 -1"<<endl;
        return 0;
    }
    string y;
    s=s1;

    int prtm=1;
    int dgit9=(s-1)/9;
//    cout<<dgit9<<endl;
    int n9nmbr=(s-1)%9;
    if(1+1+dgit9<=m)
    {
        y.push_back('1');
        int rm=m-2-dgit9;
//        cout<<rm<<endl;
        for(int i=1;i<=rm;i++) y.push_back('0');
        y.push_back((char)(n9nmbr+'0'));
        for(int i=1;i<=dgit9;i++) y.push_back('9');
//        cout<<"f**k"<<endl;

    }
    else if(1+dgit9<=m)
    {
        y.push_back((char)(1+n9nmbr+'0'));
        for(int i=1;i<=dgit9;i++) y.push_back('9');
    }

    cout<<y<<" "<<x<<endl;

    return 0;
}
