
#include<bits/stdc++.h>

using namespace std;


int main()
{

int t;
    cin>>t;

    for(int k=1;k<=t;k++)
    {

        int n, nnv=0, s=0;

        cin>>n;

        int tmp=n;

        while(tmp--)
        {
            int x;

            cin>>x;

            if(x<0)
            {
                nnv++;
            }
            s+=abs(x);
        }

        int q=n-nnv;
        int p=s;

        int g=__gcd(p, q);

        cout<<"Case "<<k<<": ";
        if(q==0) cout<<"inf"<<endl;

        else
        cout<<p/g<<"/"<<q/g<<endl;


    }

    return 0;
}


/**
3



1

1



2

-10 -3



3

3 -6 -9
*/
