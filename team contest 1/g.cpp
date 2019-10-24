#include<bits/stdc++.h>
typedef long long unsigned llu;

using namespace std;



int main()
{
    llu a, b, m, x, t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>m;

        llu t1=b%m;
//        cout<<t1<<endl;
        double t2=log(t1)/log(a);
//        cout<<t2<<endl;
        while((ceil(t2)!=floor(t2))||t2==0)
        {

            t2=log(t1)/log(a);
//            cout<<t2<<"  "<<t1<<endl;
            t1=t1+m;
        }
        cout<<floor(t2)<<endl;

    }

    return 0;
}


