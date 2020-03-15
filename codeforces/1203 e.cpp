#include<bits/stdc++.h>

#define ll long long
#define lu long long unsigned

using namespace std;


int main()
{
    map<ll, ll> mp;
    map<ll, ll>:: iterator it;
    ll n;
    cin>>n;
    while(n--)
    {
        ll x;
        cin>>x;
        mp[x]++;

    }
    set<ll> s;
    s.insert(0);

    for(it=mp.begin(); it!=mp.end(); it++)
    {

        if(it->second>2)
        {
            s.insert(it->first);
            s.insert((it->first)-1);
            s.insert((it->first)+1);
        }

    }

    for(it=mp.begin(); it!=mp.end(); it++)
    {
        if(it->second==2)
        {
            if(s.find(it->first)!=s.end())
            {
                s.insert((it->first)-1);
                s.insert((it->first)+1);
                it->second=0;
            }

            else if(s.find(it->first-1)!=s.end())
            {
                s.insert((it->first));
                s.insert((it->first)+1);
                it->second=0;
            }

            else if(s.find(it->first+1)!=s.end())
            {
                s.insert((it->first)-1);
                s.insert((it->first));
                it->second=0;
            }

        }
    }

    for(it=mp.begin(); it!=mp.end(); it++)
    {
        if(it->second==2)
        {
            if(s.find(it->first)!=s.end())
            {
                s.insert((it->first)-1);
                s.insert((it->first)+1);
                it->second=0;
            }

            else if(s.find(it->first-1)!=s.end())
            {
                s.insert((it->first));
                s.insert((it->first)+1);
                it->second=0;
            }

            else if(s.find(it->first+1)!=s.end())
            {
                s.insert((it->first)-1);
                s.insert((it->first));
                it->second=0;
            }

        }
    }


    for(it=mp.begin(); it!=mp.end(); it++)
    {
        if(it->second==2)
        {
            if(s.find(it->first)!=s.end())
            {
                s.insert((it->first)-1);
                s.insert((it->first)+1);
                it->second=0;
            }

            else if(s.find(it->first-1)!=s.end())
            {
                s.insert((it->first));
                s.insert((it->first)+1);
                it->second=0;
            }

            else if(s.find(it->first+1)!=s.end())
            {
                s.insert((it->first)-1);
                s.insert((it->first));
                it->second=0;
            }

        }
    }


    for(it=mp.begin(); it!=mp.end(); it++)
    {
        if(it->second==1)
        {
            if(s.find(it->first)!=s.end() and s.find(it->first-1)!=s.end())
            {
                s.insert((it->first)+1);
                it->second=0;
            }

            else if(s.find(it->first-1)!=s.end() and s.find(it->first+1)!=s.end())
            {
                s.insert((it->first));
                it->second=0;
            }

            else if(s.find(it->first+1)!=s.end() and s.find(it->first)!=s.end())
            {
                s.insert((it->first-1));
                it->second=0;
            }

        }
    }


    for(it=mp.begin(); it!=mp.end(); it++)
    {
        if(it->second==1)
        {
            if(s.find(it->first)!=s.end() and s.find(it->first-1)!=s.end())
            {
                s.insert((it->first)+1);
                it->second=0;
            }

            else if(s.find(it->first-1)!=s.end() and s.find(it->first+1)!=s.end())
            {
                s.insert((it->first));
                it->second=0;
            }

            else if(s.find(it->first+1)!=s.end() and s.find(it->first)!=s.end())
            {
                s.insert((it->first-1));
                it->second=0;
            }

        }
    }

    for(it=mp.begin(); it!=mp.end(); it++)
    {
        if(it->second==2)
        {
            if(s.find(it->first)!=s.end())
            {
                s.insert((it->first)-1);
                s.insert((it->first)+1);
                it->second=0;
            }

            else if(s.find(it->first-1)!=s.end())
            {
                s.insert((it->first));
                s.insert((it->first)+1);
                it->second=0;
            }

            else if(s.find(it->first+1)!=s.end())
            {
                s.insert((it->first)-1);
                s.insert((it->first));
                it->second=0;
            }

        }
    }


    for(it=mp.begin(); it!=mp.end(); it++)
    {
        if(it->second==1)
        {
            if(s.find(it->first)!=s.end() and s.find(it->first-1)!=s.end())
            {
                s.insert((it->first)+1);
                it->second=0;
            }

            else if(s.find(it->first-1)!=s.end() and s.find(it->first+1)!=s.end())
            {
                s.insert((it->first));
                it->second=0;
            }

            else if(s.find(it->first+1)!=s.end() and s.find(it->first)!=s.end())
            {
                s.insert((it->first-1));
                it->second=0;
            }

        }
    }

    for(it=mp.begin(); it!=mp.end(); it++)
    {
        if(it->second==2)
        {
            if(s.find(it->first)!=s.end())
            {
                s.insert((it->first)-1);
                s.insert((it->first)+1);
                it->second=0;
            }

            else if(s.find(it->first-1)!=s.end())
            {
                s.insert((it->first));
                s.insert((it->first)+1);
                it->second=0;
            }

            else if(s.find(it->first+1)!=s.end())
            {
                s.insert((it->first)-1);
                s.insert((it->first));
                it->second=0;
            }

            else
            {
                s.insert((it->first));
                s.insert((it->first)+1);
                it->second=0;
            }

        }
    }

//    for(it=mp.begin(); it!=mp.end(); it++)
//    {
//        if(it->second==2)
//        {
//            s.insert(it->first);
//            s.insert(it->first+1);
//
//        }
//    }

    for(it=mp.begin(); it!=mp.end(); it++)
    {
        if(it->second==1)
        {
            if(s.find(it->first)!=s.end() and s.find(it->first-1)!=s.end())
            {
                s.insert((it->first)+1);
                it->second=0;
            }

            else if(s.find(it->first-1)!=s.end() and s.find(it->first+1)!=s.end())
            {
                s.insert((it->first));
                it->second=0;
            }

            else if(s.find(it->first+1)!=s.end() and s.find(it->first)!=s.end())
            {
                s.insert((it->first-1));
                it->second=0;
            }

            else
            {
               s.insert((it->first));
                it->second=0;
            }

        }
    }

//    for(it=mp.begin(); it!=mp.end(); it++)
//    {
//        if(it->second==1)
//        {
//            s.insert(it->first);
//
//        }
//    }


    cout<<s.size()-1<<endl;

    return 0;
}


