#include<bits/stdc++.h>
typedef long long unsigned llu;

using namespace std;

int main()
{
    llu t, s;
    while(cin>>s)
    {
        if(s==0) break;
        llu r, c;
        llu tem=sqrt(s);
        llu l=tem*tem;
        llu h=(tem+1)*(tem+1);
        llu m=ceil((h+l)/2.0);
        if(l%2==0)
        {
            if(tem*tem==s)
            {
                r=1;
                c=tem;
            }
            else if(m==s)
            {
                r=tem+1;
                c=tem+1;
            }
            else if(m>s)
            {
                c=tem+1;
                llu x=m-s;
                r=c-x;
            }
            else
            {
                r=tem+1;
                llu x=s-m;
                c=r-x;
            }
        }
        else
        {
            if(l==s)
            {
                c=1;
                r=tem;
            }
            else if(m==s)
            {
                c=tem+1;
                r=tem+1;
            }
            else if(m<s)
            {
                c=tem+1;
                llu x=s-m;
                r=c-x;
            }
            else
            {
                r=tem+1;
                llu x=m-s;
                c=r-x;
            }

        }

        cout<<c<<" "<<r<<endl;

    }

    return 0;
}

