#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;



int main()
{
    int n;
    cin>>n;

    int out[n+10];

    map<int, vector<int> >mp;
    map<int, vector<int> > :: iterator it;;

    vector<int> v;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;

        int y=n-x;

        mp[y].push_back(i);
    }

    bool t=true;

    int cl=0;

    for(it=mp.begin();it!=mp.end();it++)
    {
        int x=it->first;
        if(mp[x].size()%x==0)
        {
            for(int j=0;j<mp[x].size();j++)
            {
                if(j%x==0)
                {
                    cl++;
                }
                int node=mp[x][j];
                out[node]=cl;
            }
        }

        else
        {
            t=false;
        }

    }

    if(t==false)
    {
        cout<<"Impossible"<<endl;
    }

    else{

            cout<<"Possible"<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<out[i]<<" ";
        }
    }



	return 0;
}


