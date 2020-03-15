#include<bits/stdc++.h>
#define ii pair<ll, ll>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin>>t;
//    cout<<t<<endl;
    cin.ignore();
    for(int in=1;in<=t;in++)
    {

        string x, y;
        getline(cin, x);
        getline(cin, y);
//        cout<<x<<endl;

        string xx, yy;
        for(int i=0;i<x.size();i++)
        {
            if(x[i]!=' ')
            {
                xx.push_back(tolower(x[i]));
            }
        }
//        cout<<xx<<endl;

        for(int i=0;i<y.size();i++)
        {
            if(y[i]!=' ')
            {
                yy.push_back(tolower(y[i]));
            }
        }
//        cout<<yy<<endl;

        sort(xx.begin(), xx.end());
        sort(yy.begin(), yy.end());
//        cout<<xx<<endl;
//        cout<<yy<<endl;

        cout<<"Case "<<in<<": ";

        if(xx==yy) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }

    return 0;
}


