#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b, p, x, chk=0, flag=0;

    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        if(chk==0)
        {
            chk=1;
            p=max(a, b);
            continue;
        }

        x=max(a,b);
        if(p>=x)
        {
            p=x;
        }
        else
        {
            x=min(a,b);
            if(p>=x)
            {
                p=x;
            }
            else flag=1;
        }

    }

    if(flag==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
