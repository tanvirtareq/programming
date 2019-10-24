#include<bits/stdc++.h>

using namespace std;

string binder, ingredient, reciep, requrment;

map<string, int>ing, req;
map< int, string>out;

void printmap()
{
    map<string, int>::iterator i;

    for(i=ing.begin();i!=ing.end();i++)
    {
        cout<<i->first<<"  "<<i->second<<endl;
    }

}

void print_binder()
{
    for(int i=0;i<binder.size();i++)
    {
        binder[i]=toupper(binder[i]);
        cout<<binder[i];

    }
    cout<<endl;

    return;

}

void output()
{
    map<int, string>::iterator i;

    for(i=out.begin();i!=out.end();i++)
    {
        cout<<i->second<<endl;
    }

    return;
}

int main()
{
    int t;

    cin>>t;
    cin.ignore();


    while(t--)
    {

        ing.clear();
        out.clear();

        getline(cin, binder);

        print_binder();

        int m, n, b;

        cin>>m>>n>>b;

        while(m--)
        {
            int c;
            cin>>ingredient>>c;
            ing[ingredient]=c;
        }

        cin.ignore();
        int flag=0;

        while(n--)
        {
            getline(cin, reciep);

            int k;

            cin>>k;

            int cost=0;

            while(k--)
            {
                int money;
                cin>>requrment>>money;

                req[requrment]=money;

                cost+=req[requrment]*ing[requrment];

            }
            cin.ignore();

            if(cost<=b)
            {
                flag=1;
                out[cost]=reciep;
            }

        }

        if(flag==0)
        {

            cout<<"Too expensive!"<<endl;
        }

        else if(flag==1)
        {
            output();

        }

    cout<<endl;
    }

    return 0;
}
