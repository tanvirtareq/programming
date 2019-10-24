#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, ar[100010];

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];

    }
    int mn=ar[0];
    for(int i=0;i<n;i++)
    {
        if(mn>ar[i]) mn=ar[i];
    }

    int p1=-1, p2=-1, d;

    int mnd=n;

    for(int i=0;i<n;i++)
    {
        if(ar[i]==mn)
        {
            p1=i;
            if(p2!=-1)
            {
                if(mnd>(p1-p2))
                   {
                       mnd=p1-p2;
                   }
            }
            p2=p1;
        }

    }

    cout<<mnd<<endl;

    return 0;
}
