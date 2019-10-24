#include<bits/stdc++.h>

using namespace std;

int comp(pair<string, int> p1, pair<string, int>p2)
{
    if(p1.second!=p2.second) return p1.second<p2.second;

    else return p1.first <p2.first;

}

string make_upper(string x)
{
    for(int i=0;i<x.size();i++)
    {
        x[i]=toupper(x[i]);
    }

    return x;
}

int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string titlebinder;

        getline(cin, titlebinder);
//        cout<<titlebinder<<endl;
        titlebinder= make_upper(titlebinder);

        int m, n, b;
        cin>>m>>n>>b;
        cin.ignore();
        map<string, int> mp;
        while(m--)
        {
            string i;
            int c;
            cin>>i>>c;
            cin.ignore();
            mp[i]=c;
        }
        map<string, int> mp2;
        vector<pair<string, int> >v;
        while(n--)
        {
            int tot=0;
            string namereciep;
            getline(cin, namereciep);
            int k;
            cin>>k;
            while(k--)
            {
                string req;
                int x;
                cin>>req>>x;
                cin.ignore();
                tot+=mp[req]*x;
            }
            if(tot<=b)
            {
                v.push_back(make_pair(namereciep, tot));

            }



        }
         sort(v.begin(), v.end(), comp);
        cout<<titlebinder<<endl;
        if(v.size()==0) cout<<"Too expensive!"<<endl;
        else
        {
            for(int i=0;i<v.size();i++)
            {
                cout<<v[i].first<<endl;
            }
        }
        cout<<endl;



    }

    return 0;
}
