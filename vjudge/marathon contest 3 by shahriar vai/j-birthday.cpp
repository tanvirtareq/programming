#include<bits/stdc++.h>

using namespace std;

#define lim 3

struct l{
int r;
int c;

};

void builtin(vector<l>v)
{
    long long int x=0, rl, cl;
    struct l a;
    a.r=0;
    a.c=0;

    v.push_back(a);
    x++;

    cout<<v[0].r<<endl<<v[0].c<<endl;
    a.c=1;
    a.r=1;
    v.push_back(a);
    x++;
    int t=lim;
    while(t--)
    {
        cl++;
        for(rl=1;rl<=cl;rl++)
        {
            a.c=cl;
            a.r=rl;
            v.push_back(a);
            x++;

            // if(x>lim) return;
        }
        rl--;
        for(cl=rl-1;cl>1;cl--)
        {
            a.c=cl;
            a.r=rl;
            v.push_back(a);
            x++;
            // if(x>lim) return;

        }
        cl++;
        rl++;
        for(cl=1;cl<=rl;cl++)
        {
            a.c=cl;
            a.r=rl;
            v.push_back(a);
            x++;
            // if(x>lim) return;
        }
        cl--;
        for(rl=cl-1;rl>=1;rl--)
        {
            a.c=cl;
            a.r=rl;
            v.push_back(a);
            x++;
            // if(x>lim) return;
        }
        rl++;


    }

}

int main()
{
    vector<l>v;

    builtin(v);

    long long int t, s;

    cin>>t;

    for(int i=1;i<=t;i++)
    {
        cin>>s;
        cout<<"Case "<<i<<": "<<v[3].r<<" "<<v[3].c<<endl;

    }

}

