#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

int table[2010][2010];


string x, y;

vector<char> a, b, em;

int ed(int i, int j)
{
   // cout<<i<<" "<<j<<endl;

    if(b[j]==0)
    {
        return a.size()-i;
    }
//    cout<<i<<" "<<j<<endl;

    if(a[i]==0)
    {
        return b.size()-(j);
    }
//    cout<<i<<" "<<j<<endl;

    if(table[i][j]!=-1)
        return table[i][j];

//    cout<<i<<" "<<j<<endl;

    if(a[i]==b[j])
    {
//        cout<<a[i]<<" "<<b[j]<<endl;
        return ed(i+1, j+1);
    }

//    cout<<i<<" "<<j<<endl;

    int x=1+ed(i+1, j+1);
//    cout<<x<<endl;
    int y=1+ed(i, j+1);
    int z=1+ed(i+1, j);

    int f=INT_MAX;

    cout<<a[i+1]<<endl;
    if(a[i+1]!=0 and a[i+1]==b[j] and a[i]==b[j+1])
    {
//        swap(a[i], a[i+1]);
        f=1+ed(i+2, j+2);
        cout<<f<<endl;
//        swap(a[i], a[i+1]);

    }

//    cout<<i<<" "<<j<<endl;

    int mx1=min(x, y);
    int mn2=min(mx1, z);

    table[i][j]=min(mn2, f);

    cout<<i<<" "<<j<<" "<<table[i][j]<<endl;

    return table[i][j];
}

int main()
{

    while(cin>>x>>y)
    {
        if(x=="*" and y=="*") return 0;

        memset(table, -1, sizeof table);
        a=b=em;

        for(int i=0;i<x.size();i++)
            a.push_back(x[i]);
        a.push_back(0);

        for(int i=0;i<y.size();i++)
            b.push_back(y[i]);
        b.push_back(0);

        cout<<table[0][0]<<endl;

        printf("%d\n", ed(0, 0));

      //  show(0, 0);

    }


	return 0;
}

/**
pantera aorta
zero zero
* *

*/






