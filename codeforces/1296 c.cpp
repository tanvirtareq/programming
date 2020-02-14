#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        string s;
        cin>>s;
//        vector<par<int, int> , int> v;
        int x=0, y=0;
//        v.push_back({{0, 0}, 0});
        map<pair<int, int>, int> mp;
        mp[ {0, 0}]=1;
        int mn=INT_MAX;
        int x0, y0;
        for(int i=1; i<s.size(); i++)
        {
            if(s[i-1]=='L')
                x--;
            if(s[i-1]=='R')
                x++;
            if(s[i-1]=='D')
                y--;
            if(s[i-1]=='U')
                y++;
            if(mp[ {x, y}]==0)
                mp[ {x, y}]=i+1;
            else
            {
                if(mn>(i+1-mp[ {x, y}]))
                {
                    mn=i+1-mp[ {x, y}];
                    x0=mp[ {x, y}];
                    y0=i;
                }
                mp[ {x, y}]=i+1;
            }

        }
        int i=s.size();

        if(s[i-1]=='L')
            x--;
        if(s[i-1]=='R')
            x++;
        if(s[i-1]=='D')
            y--;
        if(s[i-1]=='U')
            y++;
        if(mp[ {x, y}]==0)
            mp[ {x, y}]=i+1;
        else
        {
            if(mn>(i+1-mp[ {x, y}]))
            {
                mn=i+1-mp[ {x, y}];
                x0=mp[ {x, y}];
                y0=i;
            }
            mp[ {x, y}]=i+1;
        }


        if(mn==INT_MAX)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<x0<<" "<<y0<<endl;
        }


    }

    return 0;
}


