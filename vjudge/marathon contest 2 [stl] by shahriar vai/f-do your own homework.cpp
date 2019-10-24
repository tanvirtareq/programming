#include<bits/stdc++.h>

using namespace std;

int main()
{

    freopen("output.txt", "w", stdout);

    freopen("input.txt", "r", stdin);

    int t, n, d, x;

    map<string, int>sub;

    string xsub, dsub;

    cin>>t;

    for(int i=1;i<=t;i++)
    {
        sub.clear();

        cout<<"Case "<<i<<": ";

        cin>>n;

        while(n--)
        {
            cin>>xsub>>x;

            sub[xsub]=x;

        }

        cin>>d>>dsub;

        if(sub[dsub]>0&&sub[dsub]<=d) cout<<"Yesss"<<endl;

        else if(sub[dsub]>d&&sub[dsub]<=d+5) cout<<"Late"<<endl;

        else cout<<"Do your own homework!"<<endl;

    }



    return 0;

}


