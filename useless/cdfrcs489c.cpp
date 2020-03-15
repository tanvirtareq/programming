#include<bits/stdc++.h>

using namespace std;
int main()
{
    int m, s;

    cin>>m>>s;

    if(s<=0)
        cout<<"-1 -1";

    else if(s<10)
    {
        cout<<"1";

        for(int i=2;i<m;i++)
        {
            cout<<"0";
        }
        cout<<s-1<<" "<<s;


        for(int i=2;i<m;i++)
        {
            cout<<"0";
        }
        cout<<endl;


    }

    else
    {
        if(s==10)
        {
            cout<<"1";

        for(int i=2;i<m;i++)
        {
            cout<<"0";
        }
        cout<<s-1<<" ";
        }



    }


}
