#include<bits/stdc++.h>

using namespace std;

int main()
{
    double rans;

    long long int t, r, n, i;

    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n>>r;

        if(n==1) rans=1.0;

        else if(n%2==0)
        {
            rans=2.0;
            n=n-2;

            while(n)
            {
                if(n%2==0)
                {
                    rans=rans/(rans+1);
                    n--;
                }
                else{

                    rans=rans+1;
                    n--;
                }
            }
        }

        else
        {
            rans=0.5;
            n=n-2;

            while(n)
            {
                if(n%2==1)
                {
                    rans=rans+1;

                    n--;
                }
                else
                {
                    rans=rans/(rans+1);
                    n--;
                }
            }

        }

        double ans=(double)r*rans;
//        cout<<"Case "<<i<<": "<<ans<<endl;
        printf("Case %d: %lf\n", i, ans);


    }


    return 0;
}

