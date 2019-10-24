#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long int lld;

string findst(string x, string y, char pch[])
{

   // cout<<x<<" "<<y<<endl;
    for(int i=0;i<4;i++)
    {
        string a=x;
        string b;

        //cout<<pch[i]<<endl;

        a.push_back(pch[i]);
        b.push_back(pch[i]);
        b=b+y;

       // cout<<a<<" "<<b<<endl;

        if(a==b)
            return a;

        string d=y;
        string c;

        d.push_back(pch[i]);
        c.push_back(pch[i]);
        c=c+x;
        if(c==d)
            return c;

    }

    return "1";
}

int main()
{

    int n;
    cin>>n;

    string a[1000];

    string sp[100];
    int j=0;

    for(int i=0;i<2*n-2;i++)
    {
        cin>>a[i];
        if(a[i].size()==n-1 and j<2)
        {
            sp[j]=a[i];
            j++;
        }

    }

    char pch[100];

    pch[0]=sp[0][0];
    pch[1]=sp[0][sp[0].size()-1];
    pch[2]=sp[1][0];

    pch[3]=sp[1][sp[1].size()-1];

    string st;
    if(n==2)
    {
        st+=a[0];
        st+=a[1];
    }
    else
    st=findst(sp[0], sp[1], pch);

    if(st=="1")
    {
        for(int k=0;k<n-1;k++)
            cout<<"PS";

        return 0;
    }

   // cout<<"string is "<<st<<endl;

    map<string, char> mp;

    for(int i=0;i<2*n-2;i++)
    {
       // cout<<" "<<a[i]<<" is ";
        if(mp[a[i]]=='p')
        {
            //cout<<endl<<mp[a[i]]<<" is saved "<<endl;
            cout<<"S";
            mp[a[i]]=0;

            continue;
        }

         if(mp[a[i]]=='s')
        {
            cout<<"P";
            mp[a[i]]=0;
            continue;
        }

        string stx;
        stx.assign(st, 0, a[i].size());
       // cout<<"stx is "<<stx<<endl;
        if(stx==a[i])
        {
            cout<<"P";
            mp[stx]='p';
            continue;
        }

        string sty;
        sty.assign(st, st.size()-a[i].size(), a[i].size());
       // cout<<"sty is "<<sty<<endl;

        if(sty==a[i])
        {
            cout<<"S";
            mp[stx]='s';
            continue;
        }

        //cout<<endl;

    }



	return 0;
}


