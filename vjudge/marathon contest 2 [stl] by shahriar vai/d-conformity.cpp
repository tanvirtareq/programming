#include<bits/stdc++.h>

using namespace std;

int main()
{


    int n, x;

    map<int, int>mp;



    while(cin>>n)
    {
        if(n==0) break;

        mp.clear();

        int mx=0;

        while(n--)
        {
            int tp=5;

            while(tp--)
            {
                cin>>x;

                mp[x]++;

                if(mp[x]>mx) mx=mp[x];
            }


        }

        cout<<mx<<endl;

    }



    return 0;

}

